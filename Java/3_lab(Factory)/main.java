import java.io.IOException;

;


public class main {

    public static void main(String[] args) throws IOException, InterruptedException {
        Factory factory = new Factory();
        factory.start();
        System.in.read();
        factory.stop();
    }
}