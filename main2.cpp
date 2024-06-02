#include <vector>
#include <iostream>

using namespace std;

int n, x;

int dfs(int idx, int left, vector<int> &arr, vector<vector<int>> &memo)
{
    if (memo[idx][left] < n + 1)
    {
        return memo[idx][left];
    }
    if (left == 0)
    {
        memo[idx][left] = 0;
        return memo[idx][left];
    }
    if (idx >= n || left < 0)
    {
        return n + 1;
    }

    int t1 = dfs(idx + 1, left, arr, memo);
    int t2 = dfs(idx + 1, left - (arr[idx] / 2), arr, memo) + 1;
    int t3 = dfs(idx + 1, left - arr[idx], arr, memo) + 1;
    memo[idx][left] = min(min(t1, t2), t3);
    return memo[idx][left];
}

int main()
{
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<vector<int>> memo(n + 1, vector<int>(x + 1, n + 1));

    int ans = dfs(0, x, arr, memo);

    if (ans >= n + 1)
        cout << -1;
    else
        cout << ans;
    return 0;
}