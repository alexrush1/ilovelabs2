package Java.Calculator.Operations;

import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Sqrt extends Operations{
    public static Logger log = Logger.getLogger(Pop.class.getName());

    @Override
    protected void exceptionChecker(ExecContext context, String args[]) throws StackException, OFBException {
        if (context.getStackSize() < 1){
            throw new StackException("sqrt: not enough items on the stack");
        }
        if (context.getValue() < 0) {
            throw new StackException("sqrt: >0 only!");
        }
    }

    @Override
    public void calculate(ExecContext context, String args[]) throws StackException, OFBException {
        this.exceptionChecker(context, args);
        context.push(Math.sqrt(context.pop()));
        log.log(Level.FINE, "SQRT command successfully completed!");
    }
}
