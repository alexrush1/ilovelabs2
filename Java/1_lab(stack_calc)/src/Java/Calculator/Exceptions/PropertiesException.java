package Java.Calculator.Exceptions;

public class PropertiesException extends Exception{

    public PropertiesException() {
        super();
    }

    public PropertiesException(String message) {
        super(message);
    }

    public PropertiesException(String message, Throwable cause) {
        super(message, cause);
    }

    public PropertiesException(Throwable cause) {
        super(cause);
    }

}
