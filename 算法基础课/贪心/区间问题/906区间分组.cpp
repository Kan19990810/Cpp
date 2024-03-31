#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;

struct Range
{
    int l, r;
    bool operator<(const Range &m) const
    {
        return l < m.l;
    }
} range[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    // 排序根据左端点排序
    sort(range, range + n);
    // 根据右端点维护小根堆，heap中每个值代表的分组的右端点
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n; i++)
    {
        auto r = range[i];
        // 最小的右端点大于选点的左端点，增加分组
        if (heap.empty() || heap.top() >= r.l)
            heap.push(r.r);
        else
        {
            // 更新分组的右端点
            heap.pop();
            heap.push(r.r);
        }
    }

    cout << heap.size() << endl;

    return 0;
}