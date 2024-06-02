#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct good
{
    int a;
    int b;
    int c;
    good(int a1, int b1, int c1) : a(a1), b(b1), c(c1) {}
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<good> arr;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x + 2 * y, y, i});
    }
    auto cmp = [&](good &t1, good &t2)
    {
        if (t1.a > t2.a)
            return true;
        else if (t1.a < t2.a)
            return false;
        else
        {
            if (t1.b > t2.b)
                return true;
            else if (t1.b < t2.b)
                return false;
            else
                t1.c < t2.c;
        }
    };
    sort(arr.begin(), arr.end(), cmp);

    vector<int> ans;
    for (int i = 0; i < k; ++i)
    {
        ans.push_back(arr[i].c + 1);
    }
    sort(ans.begin(), ans.end());
    for (auto num : ans)
        cout << num << ' ';

    return 0;
}