#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

struct Range
{
    int l;
    int r;

    bool operator<(const Range &w) const
    {
        return r < w.r;
    }
} range[N];

int res = 0;
int pre = -2e9;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }

    sort(range, range + n);
    for (int i = 0; i < n; i++)
    {
        if (range[i].l > pre)
        {
            pre = range[i].r;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}