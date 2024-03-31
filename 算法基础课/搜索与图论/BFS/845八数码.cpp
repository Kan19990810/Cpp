#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int bfs(string state)
{
    queue<string> q;
    // 到达特定状态需要的交换次数
    unordered_map<string, int> d;
    q.push(state);
    d[state] = 0;
    string end = "12345678x";

    // 枚举所有可能的交换方式
    while (q.size())
    {
        string t = q.front();
        q.pop();

        if (t == end)
            return d[t];

        int distance = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a * 3 + b], t[k]);
                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]);
            }
        }
    }
    return -1;
}

int main()
{
    string state;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        state += c;
    }

    cout << bfs(state) << endl;

    return 0;
}