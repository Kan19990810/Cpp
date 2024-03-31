#include <stack>
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.push(x);
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop()
    {
        int x = stack1.top();
        stack1.pop();
        return x;
    }

    int peek()
    {
        return stack1.top();
    }

    bool empty()
    {
        return stack1.empty();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */