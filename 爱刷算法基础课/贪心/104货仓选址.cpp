#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int k = n / 2;
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += a[k] - a[i];
    }
    for (int i = k; i < n; i++)
    {
        res += a[i] - a[k];
    }
    cout << res << endl;
    return 0;
}