#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;
priority_queue<int, vector<int>, greater<int>> heap;

struct Range
{
    int l, r;

    bool operator<(Range &w) const
    {
        return l < w.l;
    }
} range[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        range[i] = {a, b};
    }

    sort(range, range + n);
    for (int i = 0; i < n; i++)
    {
        if (heap.empty() || heap.top() >= range[i].l)
        {
            heap.push(range[i].r);
        }
        else
        {
            heap.pop();
            heap.push(range[i].r);
        }
    }

    cout << heap.size() << endl;
    return 0;
}