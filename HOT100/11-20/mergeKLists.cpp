#include <queue>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 将每个链表的当前跟踪值放入优先队列中
        // 定义小根堆
        function<bool(ListNode *, ListNode *)> cmp = [&](ListNode *x, ListNode *y)
        { return x->val > y->val; };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> listsNum(cmp);
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != nullptr)
            {
                listsNum.push(lists[i]);
            }
        }

        auto dummy = new ListNode();
        auto p = dummy;

        // 每次选取优先队列中的最小值，并根据idx放入对应链表的后续值
        while (!listsNum.empty())
        {
            auto queueNode = listsNum.top();
            listsNum.pop();
            p->next = new ListNode(queueNode->val);
            p = p->next;
            queueNode = queueNode->next;
            if (queueNode != nullptr)
            {
                listsNum.push(queueNode);
            }
        }
        return dummy->next;
    }
};