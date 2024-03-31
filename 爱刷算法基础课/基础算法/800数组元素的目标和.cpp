#include <iostream>
using namespace std;
const int N = 100010;
int n, m, x;
int a[N], b[N];

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }

    for (int i = 0, j = m - 1; i < n && j >= 0; i++)
    {
        while (a[i] + b[j] > x && j >= 0)
        {
            j--;
        }
        if (a[i] + b[j] == x)
        {
            cout << i << ' ' << j << endl;
            break;
        }
    }
    return 0;
}