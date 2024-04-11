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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *prevNode = nullptr;
        ListNode *node = head;
        while (node->next != nullptr)
        {
            auto tmp = node->next;
            node->next = prevNode;
            prevNode = node;
            node = tmp;
        }
        node->next = prevNode;
        return node;
        // if (head == nullptr || head->next == nullptr)
        // {
        //     return head;
        // }

        // auto headNode = reverseList(head->next);
        // head->next->next = head;
        // head->next = nullptr;
        // return headNode;
    }
};