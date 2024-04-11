// 链表就是模拟或者递归
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        auto pointA = headA;
        auto pointB = headB;

        while (pointA != pointB)
        {
            if (pointA == nullptr)
            {
                pointA = headB;
            }
            else
            {
                pointA = pointA->next;
            }
            if (pointB == nullptr)
            {
                pointB = headA;
            }
            else
            {
                pointB = pointB->next;
            }
        }
        return pointA;
    }
};