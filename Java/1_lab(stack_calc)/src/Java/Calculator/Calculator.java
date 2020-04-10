package Java.Calculator;

import Java.Calculator.Exceptions.*;
import Java.Calculator.Operations.ExecContext;
import Java.Calculator.Operations.Operations;

import java.io.IOException;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Calculator {
    private static final Logger log = Logger.getLogger(Calculator.class.getName());
    ExecContext context = new ExecContext();

    public void calculate(Scanner reader) throws IOException {
        log.log(Level.FINE,"Enter calculator.calculate()");
        while (reader.hasNext()) {
            String line = reader.nextLine();
            if (!line.equals("EXIT")) {
                if (!line.startsWith("#")) {
                    String[] array = line.split("\\s+");
                    String OPname = array[0];
                    String[] arguments = new String[array.length - 1];
                    System.arraycopy(array, 1, arguments, 0, array.length - 1);

                    Operations operation;

                    log.log(Level.FINE,"Trying to create class for command {0}", OPname);
                    try {
                        operation = Factory.getInstance().createOperation(OPname);
                    } catch (PropertiesException ex){
                        log.log(Level.WARNING, "Can not create class", ex);
                        continue;
                    } catch (CommandCreateException ex){
                        log.log(Level.WARNING, "Unknown command", ex);
                        continue;
                    }

                    log.log(Level.FINE, "Successfully created class {0}", operation.getClass().getName());
                    log.log(Level.FINE, "Enter calculation of {0}", operation.getClass().getName());
                    try {
                        operation.calculate(context, arguments);
                    } catch (StackException | OFBException | ArgsException ex){
                        log.log(Level.WARNING,"Operation exception", ex);
                    }
                }
            } else {
                log.log(Level.FINE,"Reached \"EXIT\" command.");
                return;
            }
        }
    }

}
