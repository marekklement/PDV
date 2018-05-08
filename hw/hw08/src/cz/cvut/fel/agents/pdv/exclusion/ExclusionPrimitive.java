package cz.cvut.fel.agents.pdv.exclusion;

import cz.cvut.fel.agents.pdv.clocked.ClockedMessage;
import cz.cvut.fel.agents.pdv.clocked.ClockedProcess;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ExclusionPrimitive {

    /**
     * Stavy, ve kterych se zamek muze nachazet.
     */
    enum AcquisitionState {
        RELEASED,    // Uvolneny   - Proces, ktery vlastni aktualni instanci ExclusionPrimitive o pristup do kriticke
                     //              sekce nezada

        WANTED,      // Chteny     - Proces, ktery vlastni aktualni instanci ExclusionPrimitive zada o pristup do
                     //              kriticke sekce. Ten mu ale zatim nebyl odsouhlasen ostatnimi procesy.

        HELD         // Vlastneny  - Procesu bylo prideleno pravo pristupovat ke sdilenemu zdroji.
    }

    private ClockedProcess owner;            // Proces, ktery vlastni aktualni instanci ExclusionPrimitive

    private String criticalSectionName;      // Nazev kriticke sekce. POZOR! V aplikaci se muze nachazet vice kritickych
                                             // sekci s ruznymi nazvy!

    private String[] allAccessingProcesses;  // Seznam vsech procesu, ktere mohou chtit pristupovat ke kriticke sekci
                                             // s nazvem 'criticalSectionName' (a tak spolurozhoduji o udelovani pristupu)

    private AcquisitionState state;          // Aktualni stav zamku (vzhledem k procesu 'owner').
                                             // state==HELD znamena, ze proces 'owner' muze vstoupit do kriticke sekce
    // pamatujeme si odeslane requesty
    private Map<String, Integer> sentRequests;
    //
    private List<String> fronta;

    private Integer time;

    // Doplnte pripadne vlastni datove struktury potrebne pro implementaci
    // Ricart-Agrawalova algoritmu pro vzajemne vylouceni

    public ExclusionPrimitive(ClockedProcess owner, String criticalSectionName, String[] allProcesses) {
        this.owner = owner;
        this.criticalSectionName = criticalSectionName;
        this.allAccessingProcesses = allProcesses;

        // Na zacatku je zamek uvolneny
        this.state = AcquisitionState.RELEASED;
        // vytvorime novou hashmapu na odeslane requesty
        sentRequests = new HashMap<>();
        //
        fronta = new ArrayList<>();
    }

    /**
     * Metoda pro zpracovani nove prichozi zpravy
     *
     * @param m    prichozi zprava
     * @return 'true', pokud je zprava 'm' relevantni pro aktualni kritickou sekci.
     */
    public boolean accept(ClockedMessage m) {

        // Implementujte zpracovani prijimane zpravy informujici
        // o pristupech ke sdilenemu zdroji podle Ricart-Agrawalova
        // algoritmu. Pokud potrebujete posilat specificke zpravy,
        // vytvorte si pro ne vlastni tridy.
        //
        // POZOR! Ne vsechny zpravy, ktere v teto metode dostanete Vas
        // budou zajimat! Budou Vam prichazet i zpravy, ktere se  napriklad
        // tykaji jinych kritickych sekci. Pokud je zprava nerelevantni, tak
        // ji nezpracovavejte a vratte navratovou hodnotu 'false'. Nekdo jiny
        // se o ni urcite postara :-)
        //
        // Nezapomente se starat o cas procesu 'owner'
        // pomoci metody owner.increaseTime(). Aktualizaci
        // logickeho casu procesu s prijatou zpravou (pomoci maxima) jsme
        // za Vas jiz vyresili.
        //
        // Cas poslani prijate zpravy muzete zjistit dotazem na hodnotu
        // m.sentOn. Aktualni logicky cas muzete zjistit metodou owner.getTime().
        // Zpravy se posilaji pomoci owner.send(prijemce, zprava) a je jim auto-
        // maticky pridelen logicky cas odeslani. Retezec identifikujici proces
        // 'owner' je ulozeny v owner.id.
        if(m instanceof ClockedMessageRequest) {
            return requestAccept((ClockedMessageRequest) m);
        } else if(m instanceof ClockedMessageOK){
            return okAccept((ClockedMessageOK) m);
        } return false;
    }

    private boolean okAccept(ClockedMessageOK mess){

        if(!mess.getCriticalSectionName().equals(criticalSectionName)) return false;
        owner.increaseTime();
        sentRequests.remove(mess.sender);
        if(sentRequests.isEmpty()) state = AcquisitionState.HELD;
        //System.out.println(owner.id + " " + sentRequests.size());
        return true;
    }

    private boolean requestAccept(ClockedMessageRequest mess){
        // pokud se nejedna o nasi kritickou sekci, tak vratime false
        if (!mess.getCriticalSectionName().equals(criticalSectionName)) return false;
        //
        owner.increaseTime();
        // vytahneme si sendera
        String sender = mess.sender;
        // zkusime ho najit v sentRequests
        Integer timeSentRequest = time;
        //System.out.println(timeSentRequest+ " ");


        if(state == AcquisitionState.RELEASED) {
            owner.send(mess.sender, new ClockedMessageOK(criticalSectionName));
            return true;
        }

        if(timeSentRequest==null){
            owner.send(mess.sender, new ClockedMessageOK(criticalSectionName));
            return true;
        }

        if (timeSentRequest > mess.sentOn) {
            owner.send(mess.sender, new ClockedMessageOK(criticalSectionName));
            return true;
        }

        if(timeSentRequest== mess.sentOn && mess.sender.compareTo(owner.id) < 0){
            owner.send(mess.sender, new ClockedMessageOK(criticalSectionName));
            return true;
        }

        fronta.add(mess.sender);
        //System.out.println(owner.id + " " + mess.sender);
        return true;

    }

    public void requestEnter() {
        //System.out.println(owner.id + " " + criticalSectionName);
        state = AcquisitionState.WANTED;
        owner.increaseTime();
        time = owner.getTime();
        // Implementujte zadost procesu 'owner' o pristup
        // ke sdilenemu zdroji 'criticalSectionName'
        for (String prc : allAccessingProcesses) {
            if(owner.id.equals(prc)) continue;
            ClockedMessageRequest msg = new ClockedMessageRequest(criticalSectionName);
            // posleme request na vsechny procesy
            owner.send(prc, msg);
            // ulozime cas, kdy jsme to poslali
            sentRequests.put(prc, msg.sentOn);
            //System.out.print(prc +" ");
        }
        //System.out.println();

    }

    public void exit() {

        // Implementuje uvolneni zdroje, aby k nemu meli pristup i
        // ostatni procesy z 'allAccessingProcesses', ktere ke zdroji
        // mohou chtit pristupovat

        state = AcquisitionState.RELEASED;
        owner.increaseTime();

        for(String fr : fronta){
            ClockedMessageOK mess = new ClockedMessageOK(criticalSectionName);
            owner.send(fr,mess);

        }
        fronta.clear();

    }

    public String getName() {
        return criticalSectionName;
    }

    public boolean isHeld() {
        return state == AcquisitionState.HELD;
    }

}
