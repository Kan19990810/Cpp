class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        vector<int> c(numCourses, 0);
        int s = numCourses;
        for (auto prerequisite : prerequisites)
        {
            int x = prerequisite[0];
            int y = prerequisite[1];
            g[y].push_back(x);
            c[x]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (c[i] == 0)
            {
                q.push(i);
                s--;
            }
        }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto &y : g[t])
            {
                c[y]--;
                if (c[y] == 0)
                {
                    s--;
                    q.push(y);
                }
            }
        }
        if (s == 0)
        {
            return true;
        }
        return false;
    }
};