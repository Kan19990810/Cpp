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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        queue<TreeNode *> q({root});
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node == nullptr)
            {
                continue;
            }
            if (node->val > high)
            {
                q.push(node->left);
            }
            else if (node->val < low)
            {
                q.push(node->right);
            }
            else
            {
                sum += node->val;
                q.push(node->right);
                q.push(node->left);
            }
        }
        return sum;
    }
};