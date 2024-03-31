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
    int cum = 0;
    int cur = 0;
    void dfsCum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cum += root->val;
        dfsCum(root->left);
        dfsCum(root->right);
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);

        int t = root->val;
        root->val = cum - cur;
        cur += t;

        inorder(root->right);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        dfsCum(root);
        inorder(root);
        return root;
    }
};