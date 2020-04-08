package Test;

import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.ExecContext;
import Java.Calculator.Operations.Sqrt;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SqrtTest {

    @Test
    public void calculate() throws StackException, OFBException {
        ExecContext context = new ExecContext();
        context.push(274_133_922_084.0);
        Sqrt sqrt = new Sqrt();
        sqrt.calculate(context, new String[0]);
        assertEquals(523_578.0, context.getValue());
    }
}