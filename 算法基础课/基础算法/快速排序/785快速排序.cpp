// 快速排序 -> 分治
// 确定分界点: q[l] q[(l+r)/2] q[r] 随机
// 调整区间: 小于等于X 位于X的左边, 大于等于X 的位于X 的右边
// 递归处理左、右两端

#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[(l + r) / 2], i = l - 1, j = r + 1;

    while (i < j)
    {
        // 忽略与x相同的数，提前i++, j --
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}