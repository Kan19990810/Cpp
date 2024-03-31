class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0};
        }

        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> parent(n, -1);
        // 返回找到最长路径的叶子节点， parent作为记录路径的作用
        int x = findLongestNode(0, parent, adj);
        int y = findLongestNode(x, parent, adj);

        vector<int> path;
        parent[x] = -1;
        while (y != -1)
        {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0)
        {
            return {path[m / 2 - 1], path[m / 2]};
        }
        else
        {
            return {path[m / 2]};
        }
    }

    int findLongestNode(int u, vector<int> &parent, vector<vector<int>> &adj)
    {
        int n = adj.size();
        queue<int> qu;
        vector<bool> visit(n);
        qu.emplace(u);
        visit[u] = true;
        int node = -1;

        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();
            node = curr;
            for (auto &v : adj[curr])
            {
                if (!visit[v])
                {
                    visit[v] = true;
                    parent[v] = curr;
                    qu.emplace(v);
                }
            }
        }
        return node;
    }
};