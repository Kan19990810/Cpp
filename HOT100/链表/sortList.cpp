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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        return mysort(head, tail);
    }

    ListNode *mysort(ListNode *head, ListNode *tail)
    {
        if (head == tail)
        {
            return head;
        }
        if (head->next == tail)
        {
            if (head->val > tail->val)
            {

                tail->next = head;
                head->next = nullptr;
                return tail;
            }
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != tail && fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *mid = slow;
        ListNode *newHead = mid->next;
        mid->next = nullptr;
        tail->next = nullptr;
        return merge(mysort(head, mid), mysort(newHead, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        if (temp1 != nullptr)
        {
            temp->next = temp1;
        }
        if (temp2 != nullptr)
        {
            temp->next = temp2;
        }
        return dummy->next;
    }
};