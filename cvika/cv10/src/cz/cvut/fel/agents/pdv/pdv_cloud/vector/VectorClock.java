package cz.cvut.fel.agents.pdv.pdv_cloud.vector;

import cz.cvut.fel.agents.pdv.failure_detector.MainFD;
import cz.cvut.fel.agents.pdv.pdv_cloud.cloud_utils.IClock;
import cz.cvut.fel.agents.pdv.pdv_cloud.cloud_utils.IProcessClock;

import java.util.Arrays;

/**
 * Trida reprezentujici vektorove hodiny procesu.
 */
public class VectorClock implements IProcessClock<int[]> {

    private final int[] vectorTime;

    // id procesu - vlastnika hodin
    private final int myID;

    public VectorClock(int processes, int myID) {
        this.vectorTime = new int[processes];
        this.myID = myID;
    }

    @Override
    public void update(IClock<int[]> timestamp) {

        // Stejne jako u skalarnich hodin, cas vsech zprav ktere teprve budeme
        // odesilat musi byt ostre vetsi nez cas prave prijate zpravy
        // Proto nastavime lokalni cas na maximum z lokalniho casu a casu o
        // kterem nas informuje dorucena zprava
        for (int i = 0; i < vectorTime.length; i++){
            vectorTime[i] = Math.max(vectorTime[i], timestamp.getTime()[i]);
        }
        // Zvysime vlastni cas
        vectorTime[myID]++;
    }

    @Override
    public void onNewEvent() {

        // Zvysime vlastni cas
        vectorTime[myID]++;
    }

    @Override
    public IClock<int[]> getAsTimeStamp() {
        return new VectorTimestamp(vectorTime.clone());
    }

    @Override
    public int[] getTime() {
        return vectorTime;
    }

    @Override
    public boolean isCausalityForProcessViolated(IClock<int[]> timestamp, int process) {

        // Otestujeme, zda zpravy posilane pres proces "process" prisly v poradi,
        // v jakem je ocekavame
        return timestamp.getTime()[process] < vectorTime[process];
    }

    @Override
    public String toString() {
        return Arrays.toString(vectorTime);
    }
}
