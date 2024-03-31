#include <iostream>

using namespace std;

const int N = 100010, M = 3000010;

int n;
int a[N];
int trie[M][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!trie[p][u]) trie[p][u] = ++ idx;
        p = trie[p][u];
    }
}

int query(int x)
{
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (trie[p][!u]) 
        {
            res += 1 << i;
            p = trie[p][!u];
        }
        else p = trie[p][u];
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(query(a[i]), res);
    }

    cout << res << endl;

    return 0;
}