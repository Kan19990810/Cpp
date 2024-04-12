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
    int kthSmallest(TreeNode *root, int k)
    {
        // 中序遍历找到第k个数

        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node != nullptr || !stk.empty())
        {
            while (node != nullptr)
            {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();
            stk.pop();
            k--;
            if (k == 0)
            {
                break;
            }
            node = node->right;
        }
        return node->val;
    }
};