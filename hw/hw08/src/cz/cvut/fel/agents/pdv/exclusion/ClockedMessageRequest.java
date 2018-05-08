package cz.cvut.fel.agents.pdv.exclusion;

import cz.cvut.fel.agents.pdv.clocked.ClockedMessage;

public class ClockedMessageRequest extends ClockedMessage {

    private final String criticalSectionName;

    public ClockedMessageRequest(String name){
        this.criticalSectionName = name;
    }

    public String getCriticalSectionName() {
        return criticalSectionName;
    }
}
