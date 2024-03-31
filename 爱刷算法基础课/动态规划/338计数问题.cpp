#include <iostream>
#include <vector>
using namespace std;

int get(vector<int> num, int l, int r)
{
    int ans = 0;
    for (int i = r; i >= l; i--)
    {
        ans *= 10;
        ans += num[i];
    }
    return ans;
}

int power10(int x)
{
    int ans = 1;
    for (int i = 0; i < x; i++)
    {
        ans *= 10;
    }
    return ans;
}

int counter(int n, int x)
{
    if (n == 0)
    {
        return 0;
    }
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    int res = 0;
    int s = num.size();
    for (int i = s - 1 - !x; i >= 0; i--)
    {
        if (i < s - 1)
        {
            res += get(num, i + 1, s - 1) * power10(i);
            if (!x)
                res -= power10(i);
        }

        if (num[i] == x)
        {
            res += get(num, 0, i - 1) + 1;
        }
        else if (num[i] > x)
        {
            res += power10(i);
        }
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b && a || b)
    {
        if (a < b)
        {
            swap(a, b);
        }
        for (int i = 0; i <= 9; i++)
        {
            cout << counter(a, i) - counter(b - 1, i) << ' ';
        }
        cout << endl;
    }
    return 0;
}