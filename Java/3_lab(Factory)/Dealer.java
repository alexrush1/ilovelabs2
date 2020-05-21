public class Dealer extends Thread {
    private Storage<Auto> AutoStorage;
    private int DealerID;
    static int DealerCount = 0;
    private int delay;

    public Dealer(int delay, Storage<Auto> AutoStorage) {
        this.AutoStorage = AutoStorage;
        this.DealerID = this.DealerCount;
        this.DealerCount++;
        this.delay = delay;
    }

    @Override
    public void run() {
        while(!isInterrupted()) {
            try {
                Thread.sleep(delay);
                Auto car = AutoStorage.get();
                System.out.println("Auto solden! ID = " + car.getID());
            } catch (InterruptedException e) {
                break;
            }
        }
    }
}
