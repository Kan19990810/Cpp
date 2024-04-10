class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(vector<vector<int>> &isConnected) : parent(isConnected.size())
    {
        for (int i = 0; i < isConnected.size(); i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unit(int x, int y)
    {
        int paX = find(x);
        int paY = find(y);
        if (paX != paY)
        {
            parent[paX] = paY;
        }
    }

    int numCount()
    {
        int num = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
            {
                num++;
            }
        }
        return num;
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        UnionFind uni(isConnected);
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    uni.unit(i, j);
                }
            }
        }
        return uni.numCount();
    }
};