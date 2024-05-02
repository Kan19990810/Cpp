#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int spfa(vector<vector<pair<int, int>>> &g)
{
    int n = g.size();
    vector<bool> pass(n, false);
    vector<int> dis(n, INT_MAX);
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    pass[1] = true;

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        pass[idx] = false;

        for (auto child : g[idx])
        {
            int chd = child.first;
            int chi = child.second;
            if (dis[chi] > chd + dis[idx])
            {
                dis[chi] = chd + dis[idx];
                if (pass[chi])
                {
                    continue;
                }
                q.push(chi);
                pass[chi] = true;
            }
        }
    }

    return dis[n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({z, y});
    }
    int t = spfa(g);
    if (t == INT_MAX)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}