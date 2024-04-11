/**
 * Definition for singly-linked list.
struct ListNode {
     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [&](ListNode *x, ListNode *y)
        {
            return x->val > y->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> nodeQ(cmp);

        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != nullptr)
            {
                nodeQ.push(lists[i]);
            }
        }

        ListNode *dummy = new ListNode();
        ListNode *p = dummy;
        while (!nodeQ.empty())
        {
            ListNode *tmp = nodeQ.top();
            nodeQ.pop();
            p->next = new ListNode(tmp->val);
            p = p->next;
            tmp = tmp->next;
            if (tmp != nullptr)
            {
                nodeQ.push(tmp);
            }
        }

        return dummy->next;
    }
};