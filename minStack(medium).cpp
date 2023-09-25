class MinStack
{
private:
    stack<int> minStack;  // To store minimum values
    stack<int> mainStack; // To store all the values in same order as the input.

public:
    MinStack()
    {
    }

    void push(int val)
    {
        mainStack.push(val); // No condition needed to push in main Stack.
        if (minStack.empty() || minStack.top() >= val)
        { // If top of minStack is larger than current value, we push the current value.
            minStack.push(val);
        }
    }

    void pop()
    {
        if (minStack.top() == mainStack.top())
        { // We only pop the minStack if the top has same element as the mainStack top
            minStack.pop();
        }
        mainStack.pop(); // We don't need any condition to pop from the main stack.
    }

    int top()
    {
        return mainStack.top(); // The top value for default stack
    }

    int getMin()
    {
        return MinStack.top(); // The top value for minimum stack
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */