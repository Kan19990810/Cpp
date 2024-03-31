#include <iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N];
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    // 维护[hh, tt]中的单调递减栈， a[q[tt]]为最小值
    for (int i = 0; i < n; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)
            hh++;

        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;

        q[++tt] = i;

        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }

    cout << endl;

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)
            hh++;

        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;

        q[++tt] = i;

        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    return 0;
}