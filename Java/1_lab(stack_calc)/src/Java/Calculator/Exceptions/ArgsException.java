package Java.Calculator.Exceptions;

public class ArgsException extends Exception{

    public ArgsException() {
        super();
    }

    public ArgsException(String message) {
        super(message);
    }

    public ArgsException(String message, Throwable cause) {
        super(message, cause);
    }

    public ArgsException(Throwable cause) {
        super(cause);
    }

}
