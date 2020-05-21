public class Engine implements Detail{
    private int id;
    static int count = 0;

    public Engine() {id = count++;}

    public int getID() { return id;}
}
