package Java.Calculator;

import java.io.FileInputStream;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.logging.LogManager;
import java.util.logging.Logger;
import java.util.logging.Level;

public class Main {
    public static Logger log = Logger.getLogger(Main.class.getName());

    public static void main(String[] args) throws IOException {
        LogManager logman = LogManager.getLogManager();

        try {
            FileInputStream fis = new FileInputStream("src/Java/Calculator/logging.properties");
            logman.readConfiguration(fis);
        } catch (IOException e) {
            log.log(Level.SEVERE, "Do you think I'm stupid? The properties file is bad!", e);
        }
        log.log(Level.FINE, "Logging properties file successfully opened!");
        String input = null;
        if (args.length > 1) {
            log.log(Level.WARNING, "Too many arguments. All arguments except the first will be ignored");
            input = args[0];
        } else if (args.length == 1 ){
            input = args[0];
        }
        log.log(Level.INFO, "Creating calculator");

        Calculator calculator;
        calculator = new Calculator();

        Scanner pipe;

        if (input == null) {
            log.log(Level.FINE,"Create reader from System.in");
            pipe = new Scanner(System.in);
        } else {
            log.log(Level.FINE,"Create reader from {0}.", input);
            pipe = new Scanner(Paths.get("src/Java/Calculator" + input));
        }

        try {
            calculator.calculate(pipe);
        } catch (IOException ex) {
            log.log(Level.SEVERE,"Can not open file.", ex);
            return;
        }
        log.log(Level.FINEST, "Successfully calculated!");
    }
}