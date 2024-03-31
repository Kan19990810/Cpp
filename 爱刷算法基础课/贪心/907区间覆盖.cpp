#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    bool operator<(Range &w)
    {
        return l < w.l;
    }
} range[N];

int main()
{
    int s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n);

    bool is_valid = false;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i, right = -2e9;
        while (j < n && range[j].l <= s)
        {
            right = max(right, range[j].r);
            j++;
        }

        if (right < s)
        {
            break;
        }

        res++;

        if (right >= t)
        {
            is_valid = true;
            break;
        }

        s = right;
        i = j - 1;
    }
    if (is_valid)
    {
        cout << res << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
