package Test;

import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.ExecContext;
import Java.Calculator.Operations.Print;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class PrintTest {

    @Test
    public void calculate() throws StackException, OFBException {
        ExecContext context = new ExecContext();
        context.push(5_231_312.0);
        Print pr = new Print();
        pr.calculate(context, new String[0]);
        assertEquals(5_231_312.0, context.getValue());
    }
}