
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto dummy = new ListNode(0, head);
        auto p1 = dummy;
        auto p2 = dummy;

        for (int i = 1; i <= n; i++)
        {
            p2 = p2->next;
        }

        while (p2->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        p1->next = p1->next->next;

        auto ans = dummy->next;
        delete dummy;

        return ans;
    }
};