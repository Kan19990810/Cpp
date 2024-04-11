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
#include <unordered_map>
using namespace std;

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (cache.count(head))
        {
            return cache[head];
        }

        Node *root = new Node(head->val);
        cache[head] = root;
        root->next = copyRandomList(head->next);
        root->random = copyRandomList(head->random);
        return root;
    }

private:
    unordered_map<Node *, Node *> cache;
};