package Test;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.Define;
import Java.Calculator.Operations.ExecContext;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class DefineTest {

    @Test
    public void calculate() throws StackException, OFBException, ArgsException {
        ExecContext context = new ExecContext();
        Define def = new Define();
        String[] args = new String[2];
        args[0] = "a";
        args[1] = "5";
        def.calculate(context, args);
        assertEquals(5.0, context.getValueByKey("a"));
    }
}