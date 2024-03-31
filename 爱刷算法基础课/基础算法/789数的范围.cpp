#include <iostream>
using namespace std;

const int N = 100010;
int n, m, k;
int q[N];

int low(int q[], int k, int left, int right);
int up(int q[], int k, int left, int right);

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    while (m--)
    {
        cin >> k;
        int l = low(q, k, 0, n - 1);
        if (q[l] != k)
        {
            cout << -1 << ' ' << -1 << endl;
        }
        else
        {
            int r = up(q, k, 0, n - 1);
            cout << l << ' ' << r << endl;
        }
    }
    return 0;
}

int low(int q[], int k, int left, int right)
{
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (q[mid] >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}

int up(int q[], int k, int left, int right)
{
    while (left < right)
    {
        int mid = (left + right + 1) >> 1;
        if (q[mid] <= k)
            left = mid;
        else
            right = mid - 1;
    }
    return right;
}