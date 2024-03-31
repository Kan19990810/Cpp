#include <iostream>
using namespace std;

const int N = 100010;
int n, m, l, r;
int q[N], s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        s[i] = s[i - 1] + q[i];
    }

    while (m--)
    {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}