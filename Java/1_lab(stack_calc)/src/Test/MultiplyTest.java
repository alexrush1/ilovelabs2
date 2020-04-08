package Test;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.ExecContext;
import Java.Calculator.Operations.Minus;
import Java.Calculator.Operations.Multiply;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class MultiplyTest {

    @Test
    public void calculate() throws StackException, OFBException, ArgsException {
        ExecContext context = new ExecContext();
        context.push(913_912_900.0);
        context.push(123_131_231.0);
        Multiply mul = new Multiply();
        mul.calculate(context, new String[0]);
        assertEquals(1.12531220403779904E17, context.getValue());
    }
}