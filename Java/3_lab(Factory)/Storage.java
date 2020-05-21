import java.util.LinkedList;

public class Storage<T> extends Observable {
    private int capacity = 0;
    private LinkedList<T> details;


    public Storage(int capacity) {
        details = new LinkedList<T>();
        this.capacity = capacity;
    }

    public int getSize() {
        return this.details.size();
    }
    public int getCapacity() {
        return capacity;
    }

    public synchronized void add(T detail) throws InterruptedException {
        while (true) {
            if (details.size() < capacity) {
                details.add(detail);
                notify();
                return;
            }
            try {
                this.wait();
            } catch (InterruptedException e) {
                throw e;
            }
        }
    }

    public synchronized T get() throws InterruptedException {
        this.notifyObservers();
        while (true) {
            if (details.size() > 0) {
                T detail = details.pop();
                this.notify();
                return detail;
            }
            try {
                this.wait();
            } catch (InterruptedException e) {
                throw e;
            }
        }
    }

}
