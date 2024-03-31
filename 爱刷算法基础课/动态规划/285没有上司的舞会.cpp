#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int happy[N];
int e[N], ne[N], h[N], d[N], idx;
int r;

int dp[N][2];

void add(int l, int k)
{
    e[idx] = l;
    ne[idx] = h[k];
    h[k] = idx++;
    d[l]++;
}
// 遍历出 root节点去或者不去的最大快乐指数， 有DP 储存信息，所以不需要返回
void dfs(int root)
{
    dp[root][1] = happy[root];
    for (int i = h[root]; i != -1; i = ne[i])
    {
        int k = e[i];
        dfs(k);
        dp[root][0] += max(dp[k][0], dp[k][1]);
        dp[root][1] += dp[k][0];
    }
}

int main()
{
    memset(h, -1, sizeof(h));

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> happy[i];
    }
    for (int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;
        add(l, k);
    }

    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            r = i;
            break;
        }
    }

    dfs(r);

    cout << max(dp[r][0], dp[r][1]) << endl;
    return 0;
}