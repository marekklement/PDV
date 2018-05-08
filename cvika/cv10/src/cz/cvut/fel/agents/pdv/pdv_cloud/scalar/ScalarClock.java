package cz.cvut.fel.agents.pdv.pdv_cloud.scalar;

import cz.cvut.fel.agents.pdv.pdv_cloud.cloud_utils.IClock;
import cz.cvut.fel.agents.pdv.pdv_cloud.cloud_utils.IProcessClock;

/**
 * Trida reprezentujici skalarni hodiny procesu.
 */
public class ScalarClock implements IProcessClock<Integer> {
    private int logicalTime = 0;

    @Override
    public void update(IClock<Integer> timestamp) {

        // Cas vsech zprav poslanych po prijeti teto zpravy aktualnim procesem
        // musi byt vetsi nez cas prijate zpravy
        logicalTime = 1 + Math.max(logicalTime, timestamp.getTime());

    }

    @Override
    public void onNewEvent() {

        // S kazdou udalosti zvysime cas
        logicalTime++;

    }

    @Override
    public IClock<Integer> getAsTimeStamp() {
        return new ScalarTimestamp(logicalTime);
    }

    @Override
    public Integer getTime() {
        return logicalTime;
    }

    @Override
    public String toString() {
        return "" + logicalTime;
    }

    @Override
    public boolean isCausalityForProcessViolated(IClock<Integer> timestamp, int process) {

        // Otestujeme, zda jsme prijali zpravu z minulosti, tedy zda jsme jiz
        // poslali zpravy, ktere mely jeste cekat
        return timestamp.getTime() < logicalTime;
    }

}
