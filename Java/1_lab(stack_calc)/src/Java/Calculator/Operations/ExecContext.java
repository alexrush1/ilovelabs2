package Java.Calculator.Operations;

import java.util.HashMap;

import java.util.Stack;

public class ExecContext {
    private Stack<Double> stack = new Stack<>();
    private HashMap<String, Double> map = new HashMap<>();

    //Working with HashMap

    public Double getValueByKey(String variable){
        return map.get(variable);
    }

    public void setVariable(String variable, Double value){
        if (map.containsKey(variable)) {
            map.replace(variable, value);
        } else {
            map.put(variable, value);
        }
    }

    //Working with Stack

    public boolean isEmpty() {
        return stack.isEmpty();
    }

    public int getStackSize(){
        return stack.size();
    }

    public Double getValue(){
        return stack.peek();
    }

    public Double pop(){
        return stack.pop();
    }

    public void push(Double value){
        stack.push(value);
    }
}