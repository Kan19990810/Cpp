// 将两个已排序的数组归并
#include <iostream>
using namespace std;

const int N = 100010;
int n;
int q[N];
int tmp[N];
void merge_sort(int q[], int left, int right);

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << ' ';
    }
    cout << endl;
    return 0;
}

void merge_sort(int q[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) >> 1;
    merge_sort(q, left, mid);
    merge_sort(q, mid + 1, right);

    int k = 0, l = left, r = mid + 1;
    while (l <= mid && r <= right)
    {
        if (q[l] <= q[r])
        {
            tmp[k++] = q[l++];
        }
        else
        {
            tmp[k++] = q[r++];
        }
    }
    while (l <= mid)
    {
        tmp[k++] = q[l++];
    }
    while (r <= right)
    {
        tmp[k++] = q[r++];
    }

    for (int i = left, j = 0; i <= right; i++, j++)
    {
        q[i] = tmp[j];
    }
    return;
}