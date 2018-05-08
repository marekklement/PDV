package cz.cvut.fel.agents.pdv.exclusion;

import cz.cvut.fel.agents.pdv.clocked.ClockedMessage;

public class ClockedMessageOK extends ClockedMessage {

    private final String criticalSectionName;

    public ClockedMessageOK(String name){
        this.criticalSectionName = name;
    }

    public String getCriticalSectionName() {
        return criticalSectionName;
    }
}
