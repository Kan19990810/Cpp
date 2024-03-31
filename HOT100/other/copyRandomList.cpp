/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        for (auto node = head; node != nullptr; node = node->next->next)
        {
            auto newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        }

        for (auto node = head; node != nullptr; node = node->next->next)
        {
            auto subNode = node->next;
            if (node->random == nullptr)
            {
                subNode->random = nullptr;
            }
            else
                subNode->random = node->random->next;
        }

        auto subHead = head->next;
        for (auto node = head; node != nullptr; node = node->next)
        {
            auto subnode = node->next;
            node->next = node->next->next;
            if (node->next == nullptr)
            {
                subnode->next = nullptr;
            }
            else
                subnode->next = subnode->next->next;
        }
        return subHead;
    }
};