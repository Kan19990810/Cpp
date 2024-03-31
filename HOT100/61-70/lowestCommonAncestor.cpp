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
private:
    TreeNode *ans;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool ls = dfs(root->left, p, q);
        bool rs = dfs(root->right, p, q);
        if ((ls && rs) || ((root->val == p->val || root->val == q->val) && (ls || rs)))
        {
            ans = root;
        }
        return ls || rs || (root->val == p->val || root->val == q->val);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }
};