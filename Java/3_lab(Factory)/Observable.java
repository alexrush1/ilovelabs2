import java.util.ArrayList;

public class Observable {
    private final ArrayList<Observer> obs = new ArrayList<>();
    public void notifyObservers() {
        for (Observer ob : obs){
            ob.update();
        }
    }

    public void addObserver(Observer ob){
        obs.add(ob);
    }
}
