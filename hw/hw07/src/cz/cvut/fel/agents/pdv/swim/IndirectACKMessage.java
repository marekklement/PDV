package cz.cvut.fel.agents.pdv.swim;

import cz.cvut.fel.agents.pdv.dsand.Message;

public class IndirectACKMessage extends Message {
    boolean beenInMiddle = false;
    String from;
    String to;

    public IndirectACKMessage(String from, String to){
        this.from = from;
        this.to = to;
    }

    public boolean isBeenInMiddle() {
        return beenInMiddle;
    }

    public void setBeenInMiddle(boolean beenInMiddle) {
        this.beenInMiddle = beenInMiddle;
    }
}
