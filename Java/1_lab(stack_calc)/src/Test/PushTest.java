package Test;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.ExecContext;
import Java.Calculator.Operations.Push;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class PushTest {

    @Test
    public void calculate() throws StackException, OFBException, ArgsException {
        ExecContext context = new ExecContext();
        assertTrue(context.isEmpty());
        Push pu = new Push();
        String[] args = new String[1];
        args[0] = "2131231231";
        pu.calculate(context, args);
        assertFalse(context.isEmpty());
        assertEquals(2_131_231_231.0, context.getValue());
    }
}