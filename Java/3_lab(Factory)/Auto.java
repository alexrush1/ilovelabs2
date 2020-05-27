public class Auto implements Detail {
    private int id;
    private int EngineID;
    private int AccessoryID;
    private int BodyID;
    static int count = 0;

    public Auto(Body body, Engine engine, Accessory accessory) {
        id = count++;
        this.EngineID = engine.getID();
        this.AccessoryID = accessory.getID();
        this.BodyID = body.getID();
    }

    public int getID() { return id;}
    public int getEngineID() { return EngineID;}
    public int getBodyID() { return BodyID;}
    public int getAccessoryID() { return AccessoryID;}
}
