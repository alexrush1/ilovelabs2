package Java.Calculator.Exceptions;

public class CommandCreateException extends Exception {

        public CommandCreateException() {
            super();
        }

        public CommandCreateException(String message) {
            super(message);
        }

        public CommandCreateException(String message, Throwable cause) {
            super(message, cause);
        }

        public CommandCreateException(Throwable cause) {
            super(cause);
        }

}
