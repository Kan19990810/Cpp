#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int i = 1;
    for (int j = 1; j <= m; j++)
    {
        if (a[i] == b[j])
        {
            i++;
        }
        if (i == n + 1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}