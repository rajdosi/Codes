/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/562/
 */

class MinStack {
    private Deque<Integer> stack;
    private Deque<Integer> minStack;
    
    /** initialize your data structure here. */
    public MinStack() {
        stack = new ArrayDeque<>();
        minStack = new ArrayDeque<>();
    }
    
    public void push(int val) {
        if (stack.isEmpty() || val <= minStack.peek()) {
            minStack.push(val);
        }
        
        stack.push(val);
    }
    
    public void pop() {
        if (stack.isEmpty()) {
            throw new RuntimeException("The stack is empty");
        }
        
        int val = stack.pop();
        
        if (val == minStack.peek()) {
            minStack.pop();
        }
    }
    
    public int top() {
        if (stack.isEmpty()) {
            throw new RuntimeException("The stack is empty");
        }
        
        return stack.peek();
    }
    
    public int getMin() {
        if (stack.isEmpty()) {
            throw new RuntimeException("The stack is empty");
        }
        
        return minStack.peek();
    }
}