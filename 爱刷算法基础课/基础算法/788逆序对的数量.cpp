#include <iostream>
using namespace std;

const int N = 100010;
int n;
long long res = 0;
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

    cout << res << endl;

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

    int l = left, r = mid + 1, k = 0;
    while (l <= mid && r <= right)
    {
        if (q[l] <= q[r])
        {
            tmp[k++] = q[l++];
        }
        else
        {
            res += mid - l + 1;
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