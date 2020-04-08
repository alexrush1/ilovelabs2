package Java.Calculator.Exceptions;

public class CalcException extends Exception{

    public CalcException() {
        super();
    }

    public CalcException(String message) {
        super(message);
    }

    public CalcException(String message, Throwable cause) {
        super(message, cause);
    }

    public CalcException(Throwable cause) {
        super(cause);
    }

}
