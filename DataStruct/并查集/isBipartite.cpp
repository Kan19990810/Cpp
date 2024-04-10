class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            auto edges = graph[i];
            for (int j = 0; j < edges.size(); j++)
            {
                if (!unit(i, edges[j]))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool unit(int x, int y)
    {
        int paX = find(x);
        int paY = find(y);
        if (paX != paY)
        {
            parent[paX] = paY;
            rank[paX] = rank[y] - rank[x] + 1;
        }
        else
        {
            return abs(rank[x] - rank[y]) % 2 == 1;
        }
        return true;
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            int t = find(parent[x]);
            rank[x] += rank[parent[x]];
            parent[x] = t;
        }
        return parent[x];
    }

private:
    vector<int> parent;
    vector<int> rank;
};