import java.lang.reflect.InvocationTargetException;

public class Creator<T> extends Thread{
    private Storage<T> storage;
    private Class<T> detailCreator;
    private int delay = 0;

    public Creator(int delay, Storage<T> storage, Class<T> detailCreator) {
        this.delay = delay;
        this.storage = storage;
        this.detailCreator = detailCreator;
    }

    @Override
    public void run() {
        while(!isInterrupted()) {
            try {
                storage.add(detailCreator.getDeclaredConstructor().newInstance());
                Thread.sleep(delay);
            } catch (InterruptedException e) {
                break;
            }
            catch (InstantiationException | NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
                e.printStackTrace();
            }
        }
    }
}
