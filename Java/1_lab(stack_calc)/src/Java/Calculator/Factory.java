package Java.Calculator;

import Java.Calculator.Exceptions.CommandCreateException;
import Java.Calculator.Exceptions.PropertiesException;
import Java.Calculator.Operations.Operations;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public class Factory {

    Properties config = new Properties();

    private Factory() throws PropertiesException {
        try {
            InputStream IStream = Calculator.class.getResourceAsStream("operations.properties");
            if (IStream == null) {
                throw new IOException();
            } else {
                config.load(IStream);
            }
        } catch (Exception ex) {
            throw new PropertiesException("Can not load properties", ex);
        }
    }

    public static volatile Factory instance;

    public static Factory getInstance() throws PropertiesException {
        if (instance == null) {
            synchronized (ClassLoader.class) {
                if (instance == null) {
                    instance = new Factory();
                }
            }
        }
        return instance;
    }

    public Operations createOperation(String name) throws CommandCreateException {
        String OPname = config.getProperty(name);

        if (OPname == null) {
            throw new CommandCreateException("Unknown operation name!");
        }
        try {
            return (Operations) Class.forName(OPname).getDeclaredConstructor().newInstance();
        } catch (Exception e) {
            throw new CommandCreateException("Crashed in operation creating");
        }
    }
}
