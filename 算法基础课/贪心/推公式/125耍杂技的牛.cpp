#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 50010;

typedef pair<int, int> PII;

int n;
PII cows[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int w, s;
        cin >> w >> s;
        cows[i] = {w + s, w};
    }

    sort(cows, cows + n);

    int sum = 0, res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int w = cows[i].second, s = cows[i].first - w;
        res = max(res, sum - s);
        sum += w;
    }

    cout << res << endl;

    return 0;
}
