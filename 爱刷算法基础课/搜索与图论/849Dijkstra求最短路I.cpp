#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &g)
{
    int n = g.size();
    vector<bool> pass(n, false);
    vector<int> dis(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        int d = tmp.first;
        int idx = tmp.second;
        if (pass[idx])
        {
            continue;
        }
        pass[idx] = true;
        for (auto child : g[idx])
        {
            int chd = child.first;
            int chi = child.second;
            if (dis[chi] > chd + dis[idx])
            {
                dis[chi] = chd + dis[idx];
                pq.push({dis[chi], chi});
            }
        }
    }
    if (dis[n - 1] == INT_MAX)
        return -1;
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
    int t = dijkstra(g);
    if (t == -1)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}