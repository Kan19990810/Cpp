#include <iostream>
using namespace std;

const int N = 1000010;
int s[N], q[N];
int k, n;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    // 最小值，维护单调栈  [hh, tt]
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)
        {
            hh++;
        }
        while (hh <= tt && s[q[tt]] >= s[i])
        {
            tt--;
        }

        q[++tt] = i;
        if (i >= k - 1)
        {
            cout << s[q[hh]] << ' ';
        }
    }
    cout << endl;

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)
        {
            hh++;
        }
        while (hh <= tt && s[q[tt]] <= s[i])
        {
            tt--;
        }

        q[++tt] = i;
        if (i >= k - 1)
        {
            cout << s[q[hh]] << ' ';
        }
    }
    cout << endl;
    return 0;
}