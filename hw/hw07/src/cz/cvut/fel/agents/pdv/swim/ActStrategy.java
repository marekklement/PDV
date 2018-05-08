package cz.cvut.fel.agents.pdv.swim;

import cz.cvut.fel.agents.pdv.dsand.Message;
import cz.cvut.fel.agents.pdv.dsand.Pair;

import java.util.*;
import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.Stream;

/**
 * Trida s implementaci metody act() pro proces Failure Detector. Tuto tridu (a tridy pouzivanych zprav) budete
 * odevzdavat. Do tridy si muzete doplnit vlastni pomocne datove struktury. Hodnoty muzete inicializovat primo
 * v konstruktoru. Klicova je metoda act(), kterou vola kazda instance tridy FailureDetectorProcess ve sve metode
 * act(). Tuto metodu naimplementujte podle protokolu SWIM predstaveneho na prednasce.
 *
 * Pokud si stale jeste nevite rady s frameworkem, inspiraci muzete nalezt v resenych prikladech ze cviceni.
 */
public class ActStrategy {

    // maximalni zpozdeni zprav
    private final int maxDelayForMessages;
    // ostatni procesy beze me
    private final List<String> otherProcesses;
    // cas za ktery by mel byt detekovany mrvy proces
    private final int timeToDetectKilledProcess;
    // maximalni pocet zprav odeslanych jednim procesem
    private int upperBoundOnMessages;
    // random
    Random rd;
    // pocitadlo na cas
    long ctn;
    // moje id
    private final String id;
    // outbox zprav, kttere tento proces odesle
    List<Pair<String, Message>> toBeSend;
    // procesy, ktere jsem pingnul
    Map<String,Pair<Boolean, Long>> pinged;
    // pocitadlo na odeslane zpravy
    int messageCounter;
    // todo nastavit
    int maxRedirect = 10;

    // Definujte vsechny sve promenne a datove struktury, ktere budete potrebovat

    public ActStrategy(int maxDelayForMessages, List<String> otherProcesses,
                       int timeToDetectKilledProcess, int upperBoundOnMessages) {
        this.maxDelayForMessages = maxDelayForMessages;
        this.otherProcesses = otherProcesses;
        this.id = findId();
        this.timeToDetectKilledProcess = timeToDetectKilledProcess;
        this.upperBoundOnMessages = upperBoundOnMessages;
        rd = new Random();
        ctn = 0;
        toBeSend = new LinkedList<>();
        pinged = new HashMap<>();
        messageCounter = 0;
    }

    /**
     * Metoda je volana s kazdym zavolanim metody act v FailureDetectorProcess. Metodu implementujte
     * tak, jako byste implementovali metodu act() v FailureDetectorProcess, misto pouzivani send()
     * pridejte zpravy v podobe paru - prijemce, zprava do listu. Zpravy budou nasledne odeslany.
     * <p>
     * Diky zavedeni teto metody muzeme kontrolovat pocet odeslanych zprav vasi implementaci.
     */
    public List<Pair<String, Message>> act(Queue<Message> inbox, String disseminationProcess){

        // Od DisseminationProcess muzete dostat zpravu typu DeadProcessMessage, ktera Vas
        // informuje o spravne detekovanem ukoncenem procesu.

        // DisseminationProcess muzete poslat zpravu o detekovanem "mrtvem" procesu.
        // Zprava musi byt typu PFDMessage.
        // nejdrive si vycistime zpravy na odeslani
        toBeSend.clear();
        // pak si prohlidneme obdrzene zpravy
        checkInbox(inbox);
        // vycistime pro jistotu inbox
        inbox.clear();
        // zkontrolujeme, jestli nektere ze zprav nevyprsel cas
        checkTimeout(disseminationProcess);
        // posleme ping
        sendPing();
        ctn++;
        return toBeSend;
    }

    private void sendPing(){
        if(upperBoundOnMessages-messageCounter >0 && pinged.isEmpty()) {
            String randomProcess = otherProcesses.get(rd.nextInt(otherProcesses.size()));
            Pair<String, Message> direct = new Pair<>(randomProcess, new DirectPINGMessage());
            toBeSend.add(direct);
            messageCounter++;
            Pair<Boolean, Long> ping = new Pair<>(true, (maxDelayForMessages * 2) + ctn);
            pinged.put(randomProcess, ping);
        }
    }

    private void checkTimeout(String disseminationProcess){
        // ktere pingy se zmeni, ty musi byt z listu odstraneny
        LinkedList<String> removal = new LinkedList<>();
        // ktere pingy jsou potreba pridat
        Map<String,Pair<Boolean, Long>> addition = new HashMap<>();
        for (String pg : pinged.keySet()){
            // dotahneme si aktualni pair
            Pair<Boolean, Long> pgPair = pinged.get(pg);
            // pokud je aktualni cas vetsi, nez deadline, pak jedname
            if(pgPair.getSecond() <= ctn){

                removal.add(pg);

                Set<String> randoms = new HashSet<>();

                // musime zjistit, jestli uz byla poslana jako redirekt
                if(pgPair.getFirst()){
                    // nebyla, tak posleme x redirektu
                    boolean doOnce = true;
                    for (int i = 0; i < maxRedirect && upperBoundOnMessages-messageCounter >0;++i){

                        String randomProcess = otherProcesses.get(rd.nextInt(otherProcesses.size()));
                        while (randoms.contains(randomProcess))
                            randomProcess = otherProcesses.get(rd.nextInt(otherProcesses.size()));

                        randoms.add(randomProcess);

                        Pair<String, Message> redirect = new Pair<>(randomProcess, new IndirectPINGMessage(id, pg));
                        toBeSend.add(redirect);
                        messageCounter++;
                        // pridame aktivni pingy
                        if (doOnce) {
                            Pair<Boolean, Long> indirectPing = new Pair<>(false, (maxDelayForMessages * 4) + ctn);
                            addition.put(pg, indirectPing);
                            removal.add(pg);
                            doOnce = false;
                        }
                    }
                } else {
                    if(upperBoundOnMessages-messageCounter >0) {
                        Pair<String, Message> dissmiss = new Pair<>(disseminationProcess, new PFDMessage(pg));
                        //System.out.println(pg);
                        toBeSend.add(dissmiss);
                        messageCounter++;
                    }
                }
            }
        }
        // odstraneni znovuodeslanych
        for (String rem : removal){
            pinged.remove(rem);
        }
        // pridani novych pingu
        for (String key : addition.keySet()){
            Pair<Boolean, Long> pgPair = addition.get(key);
            pinged.put(key, pgPair);
        }

        addition.clear();
        removal.clear();

    }

    private void checkInbox(Queue<Message> inbox){
        while(!inbox.isEmpty()){
            Message mess = inbox.poll();
            pinged.remove(mess.sender);
            // dostali jsme zpravu o mrvem procesu
            if(mess instanceof DeadProcessMessage){
                DeadProcessMessage m = (DeadProcessMessage) mess;
                removeDeadProcess(m);
            // jiny proces se pta na nasi aktivitu
            } else if(mess instanceof DirectPINGMessage){
                DirectPINGMessage m = (DirectPINGMessage) mess;
                directPingOnMe(m);
            // prisla nam odpoved primo od odesilatele teto zpravy
            } else if(mess instanceof DirectACKMessage){
                DirectACKMessage m = (DirectACKMessage) mess;
                directAckOnMe(m);
            // prisel nam ping, ale nesel primo -- nemusi byt pro nas
            } else if(mess instanceof IndirectPINGMessage){
                IndirectPINGMessage m = (IndirectPINGMessage) mess;
                indirectPingOnMe(m);
            // prislo nam potvrzeni, ale prislo neprimo -- nemusi byt pro nas
            } else if(mess instanceof IndirectACKMessage){
                IndirectACKMessage m = (IndirectACKMessage) mess;
                indirectAckOnMe(m);
            // jine instance nemame, tohle by se nemelo stavat
            } else throw new IllegalArgumentException("No other instances should be detected!");
        }
    }

    private void removeDeadProcess(DeadProcessMessage m){
        otherProcesses.remove(m.getProcessID());
    }

    private void directPingOnMe(DirectPINGMessage m){
        if(upperBoundOnMessages-messageCounter >0) {
            Pair<String, Message> directMessage = new Pair<>(m.sender, new DirectACKMessage());
            toBeSend.add(directMessage);
            messageCounter++;
            // vime ze odesilatel je aktivni
        }
    }

    private void directAckOnMe(DirectACKMessage m){
        // vime ze je tedy m.sender aktivni
    }

    private void indirectPingOnMe(IndirectPINGMessage m){
        // pokud uz byla uprostred, pak ping patri nam
        if(m.isBeenInMiddle()){
            pinged.remove(m.from);
            if(upperBoundOnMessages-messageCounter >0) {
                // odpovime tedy indirectACK
                Pair<String, Message> indirectMessage = new Pair<>(m.sender, new IndirectACKMessage(m.to, m.from));
                toBeSend.add(indirectMessage);
                messageCounter++;
                // vime ze odesilatel i prostrednik jsou aktivni
            }
        // jeste nebyl u prostrednika == my jsme prostrednik
        } else {
            if(upperBoundOnMessages-messageCounter >0) {
                // staci pouze tuto zravu preposlat na m.to
                // my jsme prostrednik, takze nas uz navstivila tato zprava
                m.setBeenInMiddle(true);
                m.from = m.sender;
                Pair<String, Message> indirectMessage = new Pair<>(m.to, m);
                toBeSend.add(indirectMessage);
                messageCounter++;
            }
        }
    }

    private void indirectAckOnMe(IndirectACKMessage m){
        // pokud uz byla zprava uprostred, pak patri potvrzeni nam
        if(m.isBeenInMiddle()){
            // odstranime tedy odesilatele a from ze seznamu pingu
            pinged.remove(m.from);
        // zprava pouze pres nas prochazi -- ovsem porad je v nasem pingu, tak ji taky musime vyhodit
        } else {
            if(upperBoundOnMessages-messageCounter >0) {
                m.setBeenInMiddle(true);
                Pair<String, Message> indirectMessage = new Pair<>(m.to, m);
                toBeSend.add(indirectMessage);
                messageCounter++;
                // odstranime odesilatele z naseho pingu
            }
        }
    }

    private String findId(){
        int counter = 0;
        for (String proc : otherProcesses){
            String n = String.valueOf(counter);
            if(!proc.equals(n)){
               return n;
            }
            ++counter;
        }
        return String.valueOf(otherProcesses.size()+1);
    }

}
