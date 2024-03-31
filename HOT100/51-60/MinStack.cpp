class MinStack
{
    // 辅助栈
private:
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stk.empty())
        {
            stk.push(val);
            minStk.push(val);
            return;
        }
        int num = min(minStk.top(), val);
        stk.push(val);
        minStk.push(num);
    }

    void pop()
    {
        stk.pop();
        minStk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
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