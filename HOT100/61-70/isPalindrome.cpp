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
private:
    ListNode *reverse(ListNode *p)
    {
        if (p == nullptr || p->next == nullptr)
        {
            return p;
        }
        auto nxtP = reverse(p->next);
        p->next->next = p;
        p->next = nullptr;
        return nxtP;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        auto p1 = head, p2 = head;
        while (p1->next != nullptr && p2 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
            if (p2->next != nullptr)
            {
                p2 = p2->next;
            }
        }
        auto p2 = reverse(p1);
        p1 = head;

        while (p1->next != nullptr && p2->next != nullptr)
        {
            if (p1->val != p2->val)
            {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};