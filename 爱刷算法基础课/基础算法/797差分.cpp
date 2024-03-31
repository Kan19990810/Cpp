#include <iostream>
using namespace std;

const int N = 100010;
int n, m, l, r, c;
int q[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        b[i] += q[i];
        b[i + 1] -= q[i];
    }
    while (m--)
    {
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        cout << b[i] << ' ';
    }
    return 0;
}
