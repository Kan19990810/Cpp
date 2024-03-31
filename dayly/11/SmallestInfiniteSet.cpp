class SmallestInfiniteSet
{
public:
    SmallestInfiniteSet()
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = i + 1;
        }
    }

    int popSmallest()
    {
        int i = 0;
        while (e[i] == -1)
        {
            i++;
        }
        int t = e[i];
        e[i] = -1;
        return t;
    }

    void addBack(int num)
    {
        e[num - 1] = num;
    }

private:
    static const int N = 1010;
    int e[N];
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */