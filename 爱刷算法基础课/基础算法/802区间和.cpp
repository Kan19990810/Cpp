#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 300010;

int a[N], s[N];

vector<int> alls;
vector<pair<int, int>> query;
vector<pair<int, int>> add;

int find(int x);

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        alls.push_back(x);
        add.push_back({x, c});
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l, r});
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (int i = 0; i < n; i++)
    {
        int x;
        x = find(add[i].first);
        a[x] += add[i].second;
    }

    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        l = find(query[i].first);
        r = find(query[i].second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l + 1;
}