public class Body implements Detail {
    private int id;
    static int count = 0;

    public Body() {id = count++;}

    public int getID() { return id;}
}
