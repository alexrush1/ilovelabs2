public class Auto {
    private int id;
    private int EngineID;
    private int AccessoryID;
    private int BodyID;
    static int count = 0;

    public Auto(int EngineID, int AccessoryID, int BodyID) {
        id = count++;
        this.EngineID = EngineID;
        this.AccessoryID = AccessoryID;
        this.BodyID = BodyID;
    }

    public int getID() { return id;}
    public int getEngineID() { return EngineID;}
    public int getBodyID() { return BodyID;}
    public int getAccessoryID() { return AccessoryID;}
}
