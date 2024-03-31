#include <iostream>
#include <vector>

using namespace std;

struct good
{
    int v;
    int w;
};

const int N = 2010;
int dp[N];
vector<good> goods;
int n, m, v, w, s;

int main()
{
    cin >> n >> m;
    while (n--)
    {
        cin >> v >> w >> s;
        for (int i = 1; i < s; i *= 2)
        {
            s -= i;
            goods.push_back({v * i, w * i});
        }

        if (s > 0)
        {
            goods.push_back({v * s, w * s});
        }
    }

    for (int i = 0; i < goods.size(); i++)
    {
        for (int j = m; j >= goods[i].v; j--)
        {
            dp[j] = max(dp[j], dp[j - goods[i].v] + goods[i].w);
        }
    }

    cout << dp[m] << endl;
    return 0;
}
