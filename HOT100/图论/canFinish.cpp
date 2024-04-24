class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        vector<int> innum(numCourses, 0);
        for (auto &edge : prerequisites)
        {
            int x = edge[0];
            int y = edge[1];

            g[y].push_back(x);
            innum[x]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (innum[i] == 0)
            {
                q.push(i);
            }
        }

        vector<bool> learn(numCourses, false);
        while (!q.empty())
        {
            int k = q.size();
            while (k--)
            {
                int course = q.front();
                q.pop();
                learn[course] = true;
                for (auto child : g[course])
                {
                    if (!learn[child])
                    {
                        innum[child]--;
                        if (innum[child] == 0)
                        {
                            q.push(child);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (!learn[i])
            {
                return false;
            }
        }
        return true;
    }
};