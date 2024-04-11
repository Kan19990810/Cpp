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
        int rise = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *prev = nullptr;
        while (p1 != nullptr && p2 != nullptr)
        {
            int tmp = (rise + p1->val + p2->val) / 10;
            p1->val = (rise + p1->val + p2->val) % 10;
            rise = tmp;
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 != nullptr)
        {
            while (p1 != nullptr)
            {
                int tmp = (rise + p1->val) / 10;
                p1->val = (rise + p1->val) % 10;
                rise = tmp;
                prev = p1;
                p1 = p1->next;
            }
        }
        if (p2 != nullptr)
        {
            prev->next = p2;
            while (p2 != nullptr)
            {
                int tmp = (rise + p2->val) / 10;
                p2->val = (rise + p2->val) % 10;
                rise = tmp;
                prev = p2;
                p2 = p2->next;
            }
        }
        if (rise != 0)
        {
            prev->next = new ListNode(rise);
        }
        return l1;
    }
};