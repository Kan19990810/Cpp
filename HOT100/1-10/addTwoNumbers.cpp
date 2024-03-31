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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;

        int t = (l1->val + l2->val) / 10;
        l1->val = (l1->val + l2->val) % 10;
        while (l1->next != nullptr && l2->next != nullptr)
        {
            l1 = l1->next;
            l2 = l2->next;
            int tmp = l1->val + l2->val + t;
            t = tmp / 10;
            l1->val = tmp % 10;
        }

        if (l2->next != nullptr)
        {
            l1->next = l2->next;
        }
        while (l1->next != nullptr)
        {
            l1 = l1->next;
            int tmp = l1->val + t;
            t = tmp / 10;
            l1->val = tmp % 10;
        }
        if (t != 0)
        {
            l1->next = new ListNode(t);
        }
        return p;
    }
};