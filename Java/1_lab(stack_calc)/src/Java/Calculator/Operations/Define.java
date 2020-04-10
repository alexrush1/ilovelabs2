package Java.Calculator.Operations;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Define extends Operations{
    private final static Logger log = Logger.getLogger(Define.class.getName());

    protected void exceptionChecker(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        try {
            double value = Double.parseDouble(args[1]);
        } catch (Exception ex) {
            throw new OFBException("Unknown number!");
        }
        if (args.length > 2) {
            //System.out.println("define: extra argument noticed");
            throw new ArgsException("define: extra argument noticed");
        }
    }

    @Override
    public void calculate(ExecContext context, String args[]) throws StackException, OFBException, ArgsException {
        this.exceptionChecker(context, args);
        double value = Double.parseDouble(args[1]);
        context.setVariable(args[0], value);
        log.log(Level.FINE, "Define command successfully completed! Result: defined {0} as {1}", new Object[]{args[0], args[1]});
    }
}
