/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *node;
    void dfs(TreeNode *root, int value)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val == value)
        {
            node = root;
            return;
        }

        dfs(root->left, value);
        dfs(root->right, value);
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        dfs(cloned, target->val);
        return node;
    }
};