package Test;

import Java.Calculator.Exceptions.ArgsException;
import Java.Calculator.Exceptions.OFBException;
import Java.Calculator.Exceptions.StackException;
import Java.Calculator.Operations.Add;
import org.junit.Test;
import Java.Calculator.Operations.ExecContext;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;


public class AddTest {

    @Test
    public void calculate() throws StackException, OFBException, ArgsException {
        ExecContext context = new ExecContext();
        context.push(5.0);
        context.push(17.0);
        Add add;
        add = new Add();
        add.calculate(context, new String[0]);
        assertEquals(22.0, context.getValue());
    }

}