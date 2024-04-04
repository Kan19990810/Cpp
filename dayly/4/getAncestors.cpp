class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        for (auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            g[x].push_back(y);
        }

        vector<set<int>> pointAsc(n);
        vector<int> inNum(n, 0);
        for (auto stPoint : g)
        {
            for (auto toPoint : stPoint)
            {
                inNum[toPoint]++;
            }
        }

        queue<int> pointQueue;
        for (int i = 0; i < n; i++)
        {
            if (inNum[i] == 0)
            {
                pointQueue.push(i);
            }
        }

        while (!pointQueue.empty())
        {
            int tmpPoint = pointQueue.front();
            pointQueue.pop();

            for (auto toPoint : g[tmpPoint])
            {
                pointAsc[toPoint].insert(pointAsc[tmpPoint].begin(), pointAsc[tmpPoint].end());
                pointAsc[toPoint].insert(tmpPoint);
                inNum[toPoint]--;
                if (inNum[toPoint] == 0)
                {
                    pointQueue.push(toPoint);
                }
            }
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(pointAsc[i].begin(), pointAsc[i].end());
            ans[i] = tmp;
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};