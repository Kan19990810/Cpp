#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get(vector<int> num, int l, int r)
{
    // [l, r]
    int res = 0;
    for (int i = l; i >= r; i--)
    {
        res = res * 10 + num[i];
    }

    return res;
}

int power10(int x)
{
    int res = 1;
    while (x--)
        res *= 10;
    return res;
}

int count(int n, int x)
{
    if (!n)
        return 0;

    // 小位数 -> 大位数
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    n = num.size();

    int res = 0;
    // 遍历位数， 考虑x为 0 时不能从最高位开始
    // 考虑 x = 0 和 位数
    for (int i = n - 1 - !x; i >= 0; i--)
    {
        // 位数大于 i 的
        if (i < n - 1)
        {
            res += get(num, n - 1, i + 1) * power10(i);
            if (!x)
                res -= power10(i);
        }
        // 位数小于 i 的
        if (num[i] == x)
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > x)
            res += power10(i);
    }

    return res;
}
// 并不是动态规划
int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        if (a > b)
            swap(a, b);

        for (int i = 0; i < 10; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}