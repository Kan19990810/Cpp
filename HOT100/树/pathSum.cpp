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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // pathSum 记录以root为起点的， dfs则包含已经过的值
        int ans = dfs(root, 0, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }

private:
    int dfs(TreeNode *node, long long cur, int targetSum)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int ans = 0;
        cur += node->val;
        if (cur == targetSum)
        {
            ans++;
        }
        ans += dfs(node->left, cur, targetSum);
        ans += dfs(node->right, cur, targetSum);
        return ans;
    }
};