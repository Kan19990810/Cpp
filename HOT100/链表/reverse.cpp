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
    bool isPalindrome(ListNode *head)
    {
        ListNode *fastP = head;
        ListNode *slowP = head;

        while (fastP != nullptr && fastP->next != nullptr)
        {
            fastP = fastP->next->next;
            slowP = slowP->next;
        }
        if (fastP == slowP)
        {
            return true;
        }

        ListNode *reverseNode = reverseList(slowP);

        while (reverseNode != nullptr && head != nullptr)
        {
            if (reverseNode->val != head->val)
            {
                return false;
            }
            reverseNode = reverseNode->next;
            head = head->next;
        }
        return true;
    }
    ListNode *reverseList(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            return node;
        }
        ListNode *newHead = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }
};