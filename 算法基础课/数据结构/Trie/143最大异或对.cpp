#include <iostream>

using namespace std;

const int N = 100010, M = 3000010;

int a[N], trie[M][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i>= 0; i --)
    {
        int &s = trie[p][x >> i & 1];
        if (!s) s = ++ idx;
        p = s;
    }
}

int query(int x)
{
    int res = 0, p = 0;

    for (int i = 30; i>= 0; i --)
    {
        int s = x >> i & 1;
        if (trie[p][!s])
        {
            res += 1 << i;
            p = trie[p][!s];
        }
        else
        {
            p = trie[p][s];
        }
    }
    return res;
}

int main()
{
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    for (int i = 0; i < n; i ++)
    {
        ans = max(ans, query(a[i]));
    }

    cout << ans;

    return 0;

}