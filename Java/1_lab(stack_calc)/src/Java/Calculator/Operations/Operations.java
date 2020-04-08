package Java.Calculator.Operations;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;

public abstract class Operations {
    public abstract void calculate(ExecContext context, String args[]) throws StackException, OFBException, ArgsException;

    protected abstract void exceptionChecker(ExecContext context, String args[]) throws StackException, OFBException, ArgsException;
}
