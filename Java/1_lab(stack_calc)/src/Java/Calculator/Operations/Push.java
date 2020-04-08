package Java.Calculator.Operations;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Push extends Operations{
    public static Logger log = Logger.getLogger(Push.class.getName());

    @Override
    protected void exceptionChecker(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        if (args.length > 1){
            //System.out.println("push: extra argument noticed");
            throw new ArgsException("push: extra argument noticed");
        } else if (args.length == 0) {
            //System.out.println("push: not enough arguments");
            throw new ArgsException("push: not enough arguments");
        }
    }

    @Override
    public void calculate(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        this.exceptionChecker(context, args);
        double value;
        try {
            value = Double.parseDouble(args[0]);
        } catch (NumberFormatException | NullPointerException nfe) {
            value = context.getValueByKey(args[0]);
        }
        context.push(value);
        log.log(Level.FINE, "Push command successfully completed!");
    }
}
