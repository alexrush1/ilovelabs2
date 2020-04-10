package Java.Calculator.Operations;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Pop extends Operations{
    public static Logger log = Logger.getLogger(Pop.class.getName());

    protected void exceptionChecker(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        if (args.length != 0){
            //System.out.println("pop: extra argument noticed");
            throw new ArgsException("pop: extra argument noticed");
        }
        if (context.getStackSize() == 0){
            throw new StackException("pop: not enough items on stack");
        }
    }

    @Override
    public void calculate(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        this.exceptionChecker(context, args);
        context.pop();
        log.log(Level.FINE, "Pop command successfully completed!");
    }

}
