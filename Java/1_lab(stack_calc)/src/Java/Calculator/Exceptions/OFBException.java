package Java.Calculator.Exceptions;

public class OFBException extends CalcException{

    public OFBException() {
        super();
    }

    public OFBException(String message) {
        super(message);
    }

    public OFBException(String message, Throwable cause) {
        super(message, cause);
    }

    public OFBException(Throwable cause) {
        super(cause);
    }
}