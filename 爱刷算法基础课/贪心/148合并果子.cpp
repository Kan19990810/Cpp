#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 10010;

priority_queue<int, vector<int>, greater<int>> heap;

int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        heap.push(a);
    }

    int res = 0;
    while (heap.size() > 1)
    {
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        heap.pop();
        res += first + second;
        heap.push(first + second);
    }

    cout << res << endl;
    return 0;
}