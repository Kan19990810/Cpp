#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> q;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, s;
        cin >> w >> s;
        q.push_back({w + s, s});
    }

    sort(q.begin(), q.end());

    int s = 0;
    int res = -1e9;
    for (int i = 0; i < n; i++)
    {
        res = max(res, s - q[i].second);
        s += q[i].first - q[i].second;
    }

    cout << res << endl;
    return 0;
}