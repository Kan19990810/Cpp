#include <iostream>
using namespace std;

const int N = 100010;
int n, res = 0;
int q[N], s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }

    for (int i = 1, j = 1; i <= n; i++)
    {
        s[q[i]]++;
        while (s[q[i]] > 1)
        {
            s[q[j]]--;
            j++;
        }

        res = max(res, i - j + 1);
    }
    cout << res;
    return 0;
}