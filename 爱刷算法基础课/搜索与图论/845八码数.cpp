#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

queue<string> queue_s;
unordered_map<string, int> dist;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
string e = "12345678x";

int bfs(string str)
{
    dist[str] = 0;
    queue_s.push(str);

    while (!queue_s.empty())
    {
        string s = queue_s.front();
        queue_s.pop();
        if (s == e)
        {
            return dist[s];
        }

        int k = s.find('x');
        int d = dist[s];
        int x_ = k / 3;
        int y_ = k % 3;
        for (int i = 0; i < 4; i++)
        {
            int x = x_ + dx[i], y = y_ + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                swap(s[k], s[3 * x + y]);
                if (!dist.count(s))
                {
                    dist[s] = d + 1;
                    queue_s.push(s);
                }
                swap(s[k], s[3 * x + y]);
            }
        }
    }
    return -1;
}

int main()
{
    string s;
    for (int i = 1; i <= 9; i++)
    {
        char c;
        cin >> c;
        s += c;
    }
    cout << bfs(s);
    return 0;
}