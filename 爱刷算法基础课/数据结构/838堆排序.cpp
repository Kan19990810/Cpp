#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N];
int n, m, s;

// void down(int u)
// {
//     int t = u;
//     if (2 * u <= s && h[t] > h[2 * u])
//     {
//         t = 2 * u;
//     }
//     if (2 * u + 1 <= s && h[t] > h[2 * u + 1])
//     {
//         t = 2 * u + 1;
//     }
//     if (t != u)
//     {
//         swap(h[u], h[t]);
//         down(t);
//     }
// }
void down(int u)
{
    int t = u;
    if (u * 2 <= s && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    // scanf("%d%d", &n, &m);

    // for (int i = 1; i <= n; i++)
    // {
    //     scanf("%d", &h[i]);
    // }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << h[i] << ' ';
    // }
    // cout << endl;

    s = n;

    // for (int i = n / 2; i; i--)
    // {
    //     down(i);
    // }
    for (int i = n / 2; i; i--)
        down(i);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << h[i] << ' ';
    // }
    // cout << endl;

    // s = n;
    for (int i = 1; i <= m; i++)
    {
        cout << h[1] << ' ';
        swap(h[1], h[s]);
        s--;
        down(1);
    }
    return 0;
}