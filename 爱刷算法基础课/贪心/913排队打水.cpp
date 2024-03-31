#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        heap.push(x);
    }
    long long res = 0;
    while (!heap.empty())
    {
        int t = heap.top();
        heap.pop();
        int s = heap.size();
        res += (long long)s * t;
    }
    cout << res << endl;
    return 0;
}