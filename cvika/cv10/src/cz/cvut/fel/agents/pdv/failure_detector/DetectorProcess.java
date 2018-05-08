package cz.cvut.fel.agents.pdv.failure_detector;

import cz.cvut.fel.agents.pdv.dsand.DSProcess;
import cz.cvut.fel.agents.pdv.dsand.Message;

import java.util.*;
import java.util.function.BiConsumer;

/**
 * Trida DetectorProcess. Ukolem kazde instance je detekovat ukoncene procesy pomoci all-to-all heartbeat algoritmu.
 * Krome implementace samotne metody act() budete pravdepodobne potrebovat zavest pomocne datove struktury.
 *
 * V metode act() mate napovedu k postupu.
 * Pokud si stale jeste nevite rady s frameworkem, inspiraci muzete nalezt v resenych prikladech ze cviceni.
 */
public class DetectorProcess extends DSProcess {

    // parametry posilani zprav
    // jak casto se maji zpravy posilat
    private final int period;
    // casovy limit k prijeti heartbeatu, typicky nasobek periody
    private final int timeout;

    // Struktura udrzujici prehled o tom, kdy nam prisel naposledy heartbeat
    // od kazdeho z procesu
    private final Map<String, Integer> heartbeats;
    // Mnozina mrtvych procesu
    private final Set<String> deadProcesses = new HashSet<>();

    // Interni pocitadlo, kolikrat byl proces vzbuzen.
    // Procesy se budi v kazdem kroku simulace vsechny
    // jejich wakeCounters tedy nemaji zadny drift
    private int wakeCount = 0;

    private final List<String> ALL_PROCESSES;

    public DetectorProcess(String id, Queue<Message> inbox, BiConsumer<String, Message> outbox,
                           int maxDelay, List<String> processes) {
        super(id, inbox, outbox);

        this.period = 10;
        // Maximalni doba mezi heartbeaty nastane, pokud jeden heartbeat bude dorucen ihned
        // a nasledujici bude zpozden o donu maximalniho mozneho zpozdeni
        this.timeout = period + maxDelay;

        this.ALL_PROCESSES = processes;

        this.heartbeats = new HashMap<>();
        for (String process : ALL_PROCESSES){
            heartbeats.put(process, 0);
        }
    }

    @Override
    public void act() {

        // Muzete predpokladat, ze se zpravy neztraceji, jen zpozduji o maximalne maxDelay tiku DS
        // 1. zajistete, ze se s kazdou periodou poslou heartbeats vsem ostatnim procesum
        // 2. pokud obdrzite heartbeat od jineho procesu, aktualizujte si databazi zivych procesu
        // 3. detekujte havarovane procesy, takovy proces vypiste prave jednou

        // Zkontrolujeme, zda mame posilat hearbeaty
        if (wakeCount % period == 0) {
            for(String process : ALL_PROCESSES){
                if (process != id){
                    send(process, new HeartbeatMessage());
                }
            }
        }
        while (!inbox.isEmpty()) {
            // Pokud nam prisla zprava, aktualizujeme mapu naposledy prijatych heartbeatu
            HeartbeatMessage message = (HeartbeatMessage) inbox.poll();
            heartbeats.put(message.sender, wakeCount);
        }

        // Zkontrolujeme, jestli se nektery z procesu neozval uz tak dlouho, ze ho jiz
        // muzeme prohlasit za mrtvy
        for(String process : ALL_PROCESSES){
            if (process != id && !deadProcesses.contains(process)){
                if (wakeCount - heartbeats.get(process) > period + timeout){
                    System.err.println(id + " detected failed process: " + process);
                    deadProcesses.add(process);
                }
            }
        }

        // Inkrementujeme lokalni hodiny
        wakeCount++;
    }
}
