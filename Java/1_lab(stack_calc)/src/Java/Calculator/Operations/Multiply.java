package Java.Calculator.Operations;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Multiply extends Operations{
    public static Logger log = Logger.getLogger(Add.class.getName());

    @Override
    protected void exceptionChecker(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        if (context.getStackSize() < 2){
            throw new StackException("multiply: not enough items on the stack");
        }
        if (args.length > 0) {
            //System.out.println("multiply: extra argument noticed");
            throw new ArgsException("multiply: extra argument noticed");
        }
    }

    @Override
    public void calculate(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        this.exceptionChecker(context, args);
        context.push(context.pop() * context.pop());
        log.log(Level.FINE, "Multiply command successfully completed!");
    }
}
