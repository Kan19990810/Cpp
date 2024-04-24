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
    TreeNode *startNode;
    TreeNode *fa[100001];
    void dfs(TreeNode *node, TreeNode *from, int start)
    {
        if (node == nullptr)
        {
            return;
        }

        fa[node->val] = from;
        if (node->val == start)
        {
            startNode = node;
        }

        dfs(node->left, node, start);
        dfs(node->right, node, start);
    }

    int maxDepth(TreeNode *node, TreeNode *from)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int res = 0;
        if (node->left != from)
        {
            res = max(res, maxDepth(node->left, node));
        }

        if (node->right != from)
        {
            res = max(res, maxDepth(node->right, node));
        }

        if (fa[node->val] != from)
        {
            res = max(res, maxDepth(fa[node->val], node));
        }
        return res + 1;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        // 记录父结点
        dfs(root, nullptr, start);
        return maxDepth(startNode, startNode) - 1;
    }
};