#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
bool s[N];

int ans = N;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u)
{
    s[u] = true;

    int sum = 1, res = 0;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!s[j])
        {
            int r = dfs(j);
            res = max(res, r);
            sum += r;
        }
    }
    res = max(res, n - sum);

    ans = min(res, ans);
    return sum;
}


int main()
{
    memset(h, -1, sizeof(h));

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}