import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Properties;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class Factory {
    //private engineSupplier;
    private Storage<Engine> EngineStorage;
    private Storage<Accessory> AccessoryStorage;
    private Storage<Body> BodyStorage;
    private Storage<Auto> AutoStorage;

    private ThreadPoolExecutor workers;
    private final ArrayList<Creator<? extends Detail>> suppliers = new ArrayList<>();
    private final ArrayList<Dealer> dealers = new ArrayList<>();

    Properties config = new Properties();

    public Factory() {

        try {
            InputStream IStream = Factory.class.getResourceAsStream("resources/parametres.config");
            if (IStream == null) {
                throw new IOException();
            } else {
                config.load(IStream);
            }
        } catch (Exception ex) {
            ex.getStackTrace();
        }

        int StorageBodySize = Integer.parseInt(config.getProperty("StorageBodySize"));
        int StorageEngineSize = Integer.parseInt(config.getProperty("StorageEngineSize"));
        int StorageAccessorySize = Integer.parseInt(config.getProperty("StorageAccessorySize"));
        int StorageAutoSize = Integer.parseInt(config.getProperty("StorageAutoSize"));
        int WorkersCount = Integer.parseInt(config.getProperty("Workers"));
        int DealersCount = Integer.parseInt(config.getProperty("Dealers"));

        EngineStorage = new Storage<>(StorageEngineSize);
        AccessoryStorage = new Storage<>(StorageBodySize);
        BodyStorage = new Storage<>(StorageAccessorySize);
        AutoStorage = new Storage<>(StorageAutoSize);

        workers = (ThreadPoolExecutor) Executors.newFixedThreadPool(WorkersCount);

        AutoStorage.addObserver(new AutoStorageController(BodyStorage, EngineStorage, AccessoryStorage, AutoStorage, workers));

        suppliers.add(new Creator<Body>(1000, BodyStorage, Body.class));
        suppliers.add(new Creator<Engine>(1000, EngineStorage, Engine.class));
        suppliers.add(new Creator<Accessory>(1000, AccessoryStorage, Accessory.class));

        for (int i = 0; i < DealersCount; i++) {
            dealers.add(new Dealer(5000, AutoStorage));
        }

    }

    public void start() {
        for (Creator<? extends Detail> Creator : suppliers) {
            Creator.start();
        }
        for (Dealer dealer : dealers) {
            dealer.start();
        }
    }

    public void stop() {
        for (Creator<? extends Detail> Creator : suppliers) {
            Creator.interrupt();
        }
        for (Dealer dealer : dealers) {
            dealer.interrupt();
        }
        workers.shutdown();
    }

}
