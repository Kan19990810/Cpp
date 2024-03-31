// dfs = 回溯
#include <iostream>
using namespace std;

const int N = 10;
int st[N], e[N];
int n;

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << e[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            e[x] = i;
            dfs(x + 1);
            st[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}