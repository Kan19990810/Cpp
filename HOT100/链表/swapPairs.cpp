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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *p1 = head;
        ListNode *p2 = head->next;

        while (p1 != nullptr && p2 != nullptr)
        {
            ListNode *nxt = p2->next;
            prev->next = p2;
            p2->next = p1;
            p1->next = nxt;

            prev = p1;
            p1 = nxt;
            if (p1 != nullptr)
            {
                p2 = p1->next;
            }
        }
        return dummy->next;
    }
};