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
public:
    // 验证需要最大最小值
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LONG_MAX, LONG_MIN);
    }

private:
    bool dfs(TreeNode *node, long long mx, long long mi)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->val >= mx || node->val <= mi)
        {
            return false;
        }

        return dfs(node->left, node->val, mi) && dfs(node->right, mx, node->val);
    }
};