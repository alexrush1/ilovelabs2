package Test;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.Division;
import Java.Calculator.Operations.ExecContext;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class DivisionTest {

    @Test
    public void calculate() throws StackException, OFBException, ArgsException {
        ExecContext context = new ExecContext();
        context.push(1337.0);
        context.push(304_836.0);
        Division div = new Division();
        div.calculate(context, new String[0]);
        assertEquals(228.0, context.getValue());
    }
}