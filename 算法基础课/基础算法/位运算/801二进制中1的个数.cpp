#include <iostream>

using namespace std;

int n, x;

// 最低位置的1
int lowbit(int x)
{
    return x & -x;
}
// (x >> 1) % 2
int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        int res = 0;
        while (x)
            x -= lowbit(x), res++;
        printf("%d ", res);
    }
    return 0;
}