#include <iostream>
#include <cstring>
using namespace std;

const int N = 200010;
int e[N], ne[N], h[N], idx;
bool p[N];
int n, a, b;
int res = N;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u)
{
    p[u] = true;

    int sum = 1, ans = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!p[j])
        {
            int r = dfs(j);
            sum += r;
            ans = max(ans, r);
        }
    }
    ans = max(ans, n - sum);
    res = min(res, ans);
    return sum;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << res;
    return 0;
}