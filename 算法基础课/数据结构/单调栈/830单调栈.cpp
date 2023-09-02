// 单调栈 左边离他最近的数的位置
#include <iostream>

using namespace std;

const int N = 100010;

int n, s[N], tt = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (tt && s[tt] >= x) tt--;
        if (tt) printf("%d ", s[tt]);
        else printf("-1 ");
        s[++tt] = x;
    }
    return 0;
}