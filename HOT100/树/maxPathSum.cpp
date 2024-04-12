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
    // 暴力遍历每个节点作为中间节点
    // dfs 返回以节点为端点的最大路径
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        dfs(root);
        return ans;
    }

private:
    int ans = INT_MIN;
    // dfs 返回以节点为端点的最大路径, DFS中可以不选
    int dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int l = dfs(node->left);
        int r = dfs(node->right);

        ans = max(l + r + node->val, ans);
        return max(max(l, r) + node->val, 0);
    }
};