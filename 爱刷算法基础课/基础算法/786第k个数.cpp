#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int q[N];

int quick_sort_k(int q[], int left, int right, int k);

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    cout << quick_sort_k(q, 0, n - 1, k) << endl;

    return 0;
}

int quick_sort_k(int q[], int left, int right, int k)
{
    if (left == right)
    {
        return q[left];
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
    // 结束while时 l = r
    int dis = r - left + 1;
    if (k <= dis)
        return quick_sort_k(q, left, r, k);
    else
        return quick_sort_k(q, r + 1, right, k - dis);
}