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
    int ans = 0;
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {INT_MAX / 2, 0};
        }

        auto leftVal = dfs(root->left);
        auto rightVal = dfs(root->right);
        int leftmi = leftVal.first, leftma = leftVal.second;
        int rightmi = rightVal.first, rightma = rightVal.second;

        int mi = min(leftmi, rightmi);
        int ma = max(leftma, rightma);

        if (mi < INT_MAX / 2)
        {
            ans = max(ans, abs(root->val - mi));
        }
        if (ma > 0)
        {
            ans = max(ans, abs(root->val - ma));
        }

        mi = min(root->val, min(leftmi, rightmi));
        ma = max(root->val, max(leftma, rightma));

        return {mi, ma};
    }

    int maxAncestorDiff(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};