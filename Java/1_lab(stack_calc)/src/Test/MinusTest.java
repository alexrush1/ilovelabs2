package Test;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.ExecContext;
import Java.Calculator.Operations.Minus;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class MinusTest {

    @Test
    public void calculate() throws StackException, OFBException, ArgsException {
        ExecContext context = new ExecContext();
        context.push(1_241_322.0);
        context.push(123_131_231.0);
        Minus min = new Minus();
        min.calculate(context, new String[0]);
        assertEquals(121_889_909.0, context.getValue());
    }
}