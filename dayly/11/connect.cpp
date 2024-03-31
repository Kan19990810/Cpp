/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }

        queue<Node *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int n = nodes.size();
            Node *last = nullptr;
            for (int i = 1; i <= n; i++)
            {
                Node *f = nodes.front();
                nodes.pop();
                if (f->left)
                {
                    nodes.push(f->left);
                }
                if (f->right)
                {
                    nodes.push(f->right);
                }
                if (i != 1)
                {
                    last->next = f;
                }
                last = f;
            }
        }
        return root;
    }
};