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
    int ans = INT_MIN;

    // dfs 返回的是该根节点为端点的最长路径, 或者不选
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);

        ans = max(ans, l + r + root->val);

        return max(0, max(l, r) + root->val);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int unused = dfs(root);

        return ans;
    }
};