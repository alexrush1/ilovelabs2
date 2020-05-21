
public class Worker extends Thread {
    private Storage<Engine> EngineStorage;
    private Storage<Accessory> AccessoryStorage;
    private Storage<Body> BodyStorage;
    private Storage<Auto> AutoStorage;

    public Worker(Storage<Engine> EngineStorage,Storage<Accessory> AccessoryStorage, Storage<Body> BodyStorage, Storage<Auto> AutoStorage) {
        this.EngineStorage = EngineStorage;
        this.AccessoryStorage = AccessoryStorage;
        this.BodyStorage = BodyStorage;
        this.AutoStorage = AutoStorage;
    }

    @Override
    public void run() {
        while(!isInterrupted()) {
            try {
                Thread.sleep(1000);
                Engine engine = EngineStorage.get();
                Body body = BodyStorage.get();
                Accessory acs = AccessoryStorage.get();
                Auto auto = new Auto(engine.getID(), body.getID(), acs.getID());
                AutoStorage.add(auto);
            } catch (InterruptedException e) {
                return;
            }
        }
    }

}
