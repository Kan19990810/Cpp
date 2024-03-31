#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
int a[N], s[N];

// 所有用到的端点位置
vector<int> alls;

// 加法和询问
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});

        alls.push_back(x);
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // add操作
    for (int i = 0; i < n; i++)
    {
        int x = find(add[i].first);
        a[x] += add[i].second;
    }

    // 前缀和操作
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    // 查询操作
    for (int i = 0; i < m; i++)
    {
        int l = find(query[i].first);
        int r = find(query[i].second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}