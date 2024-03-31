class FrontMiddleBackQueue
{
public:
    FrontMiddleBackQueue()
    {
        l[1] = 0;
        r[0] = 1;
        idx = 2;
        size_ = 0;
    }

    void pushFront(int val)
    {
        e[idx] = val;
        l[idx] = 0;
        r[idx] = r[0];
        l[r[0]] = idx;
        r[0] = idx;
        idx++;
        size_++;
    }

    void pushMiddle(int val)
    {
        int t = 0;
        for (int i = 0; i < size_ / 2; i++)
        {
            t = r[t];
        }

        e[idx] = val;
        l[idx] = t;
        r[idx] = r[t];
        l[r[t]] = idx;
        r[t] = idx;
        idx++;
        size_++;
    }

    void pushBack(int val)
    {
        e[idx] = val;
        r[idx] = 1;
        l[idx] = l[1];
        r[l[1]] = idx;
        l[1] = idx;
        idx++;
        size_++;
    }

    int popFront()
    {
        if (size_ == 0)
        {
            return -1;
        }
        int tmp = e[r[0]];
        l[r[r[0]]] = 0;
        r[0] = r[r[0]];
        size_--;
        return tmp;
    }

    int popMiddle()
    {
        if (size_ == 0)
        {
            return -1;
        }
        int t = 0;
        for (int i = 0; i < (size_ + 1) / 2; i++)
        {
            t = r[t];
        }
        int tmp = e[t];
        r[l[t]] = r[t];
        l[r[t]] = l[t];
        size_--;
        return tmp;
    }

    int popBack()
    {
        if (size_ == 0)
        {
            return -1;
        }
        int tmp = e[l[1]];
        r[l[l[1]]] = 1;
        l[1] = l[l[1]];
        size_--;
        return tmp;
    }

private:
    static const int N = 1010;
    int size_;
    int e[N], l[N], r[N], idx;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */