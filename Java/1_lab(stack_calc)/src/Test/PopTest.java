package Test;

import Java.Calculator.Operations.ExecContext;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class PopTest {

    @Test
    public void calculate() {
        ExecContext context = new ExecContext();
        assertTrue(context.isEmpty());
        context.push(501_212_030_231.0);
        assertEquals(501_212_030_231.0, context.getValue());
        context.pop();
        assertTrue(context.isEmpty());
    }
}