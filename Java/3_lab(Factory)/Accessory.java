public class Accessory implements Detail{
    private int id;
    static int count = 0;

    public Accessory() {id = count++;}

    public int getID() { return id;}
}
