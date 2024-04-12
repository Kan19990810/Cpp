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
    // 在递归的过程中找到答案，不要拘泥于递归能够直接返回答案

    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return ans - 1;
    }

private:
    int ans = 0;
    int dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int l = dfs(node->left);
        int r = dfs(node->right);
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }
};