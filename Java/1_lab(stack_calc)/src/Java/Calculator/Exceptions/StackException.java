package Java.Calculator.Exceptions;

public class StackException extends CalcException{

    public StackException() {
        super();
    }

    public StackException(String message) {
        super(message);
    }

    public StackException(String message, Throwable cause) {
        super(message, cause);
    }

    public StackException(Throwable cause) {
        super(cause);
    }
}