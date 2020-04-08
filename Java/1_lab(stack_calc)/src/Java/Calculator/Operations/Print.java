package Java.Calculator.Operations;

import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Print extends Operations{
    public static Logger log = Logger.getLogger(Add.class.getName());

    @Override
    protected void exceptionChecker(ExecContext context, String args[]) throws StackException, OFBException {
        if (context.getStackSize() < 1){
            //System.out.println("print: not enough items on stack");
            throw new StackException("print: not enough items on stack");
        }
    }

    @Override
    public void calculate(ExecContext context, String args[]) throws StackException, OFBException {
        this.exceptionChecker(context, args);
        System.out.println(context.getValue());
        log.log(Level.FINE, "Print command successfully completed!");
    }
}
