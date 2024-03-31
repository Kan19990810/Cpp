#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisor(int a)
{
    vector<int> res;
    // 求所有约数， 不要求每个约数的个数
    for (int i = 1; i <= a / i; i++)
    {
        if (a % i == 0)
        {
            res.push_back(i);
            if (i != a / i)
                res.push_back(a / i);
        }
    }
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        vector<int> res = get_divisor(a);
        for (int t : res)
            cout << t << ' ';
        cout << endl;
    }
    return 0;
}