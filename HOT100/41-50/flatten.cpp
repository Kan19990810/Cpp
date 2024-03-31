/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    vector<TreeNode *> res;

    void preOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        res.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }

public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        preOrder(root);
        auto p = root;
        for (int i = 1; i < res.size(); i++)
        {
            p->right = res[i];
            // cout << res[i]->val << ' ';
            p->left = nullptr;
            p = p->right;
        }
    }
};