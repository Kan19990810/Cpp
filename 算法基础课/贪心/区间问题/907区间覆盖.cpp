#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int st, ed;
int n;

struct Range
{
    int l, r;

    bool operator<(const Range &m) const
    {
        return l < m.l;
    }
} range[N];

int main()
{
    cin >> st >> ed;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    // 根据左端点排序
    sort(range, range + n);

    int res = 0;
    bool success = false;
    // 每一次选取一个能覆盖st且覆盖范围最大的区间
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j++;
        }

        if (r < st)
        {
            res = -1;
            break;
        }

        res++;

        if (r >= ed)
        {
            success = true;
            break;
        }

        st = r;
        i = j - 1;
    }

    if (!success)
        res = -1;
    cout << res << endl;

    return 0;
}