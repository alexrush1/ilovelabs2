import java.util.concurrent.ThreadPoolExecutor;

public class AutoStorageController implements Observer {

    private final Storage<Body> BodyStorage;
    private final Storage<Engine> EngineStorage;
    private final Storage<Accessory> AccessoryStorage;
    private final Storage<Auto> AutoStorage;
    private final ThreadPoolExecutor workers;

    public AutoStorageController(Storage<Body> bodyStorage, Storage<Engine> EngineStorage,
                                 Storage<Accessory> accessoryStorage, Storage<Auto> autoStorage, ThreadPoolExecutor workers) {
        this.BodyStorage = bodyStorage;
        this.EngineStorage = EngineStorage;
        this.AccessoryStorage = accessoryStorage;
        this.AutoStorage = autoStorage;
        this.workers = workers;
    }


    @Override
    public void update() {
        long carsInProgress = workers.getTaskCount() - workers.getCompletedTaskCount();
        if ((double) (AutoStorage.getSize() + carsInProgress) / AutoStorage.getCapacity() < 0.2) {
            System.out.println(("New task!"));
            for (int i = 0; i < 0.2 * AutoStorage.getCapacity() + 1; i++){
                workers.execute(new Task());
            }
        }
    }

    private class Task implements Runnable {
        @Override
        public void run() {
            try {
                Body body = BodyStorage.get();
                Engine motor = EngineStorage.get();
                Accessory accessory = AccessoryStorage.get();

                Auto auto = new Auto(body, motor, accessory);
                AutoStorage.add(auto);
                System.out.println("Auto created! ID = " + auto.getID() + " (EngineID = " + auto.getEngineID() +
                        "; BodyID = " + auto.getBodyID() + "; AccessoryID = " + auto.getAccessoryID() + ")");
                Thread.sleep(1000);
            } catch (InterruptedException ex){
                System.out.println(("Thread was interrupted"));
            }
        }
    }

}