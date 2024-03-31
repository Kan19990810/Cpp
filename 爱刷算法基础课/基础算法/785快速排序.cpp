// 快排 分治
// 重点边界问题
// l, r 表示的含义l的左侧均小于mid, r 的右侧均大于mid
// 连续mid 值推进l, r  do -> while, 允许跳过等于mid的值
#include <iostream>
using namespace std;

const int N = 100010;
int n;
int q[N];

void quick_sort(int q[], int left, int right);

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << ' ';
    }
    cout << endl;
    return 0;
}

void quick_sort(int q[], int left, int right)
{
    // 递归结束条件
    if (left >= right)
    {
        return;
    }

    int l = left - 1, r = right + 1;
    int x = q[(left + right) >> 1];
    while (l < r)
    {
        do
            l++;
        while (q[l] < x);
        do
            r--;
        while (q[r] > x);
        if (l < r)
            swap(q[l], q[r]);
    }
    quick_sort(q, left, r);
    quick_sort(q, r + 1, right);
    return;
}