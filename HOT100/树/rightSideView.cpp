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
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        // 层序遍历 每一层右边的第一个数
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto node = q.front();
                q.pop();
                if (i == 0)
                {
                    ans.push_back(node->val);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
            }
        }
        return ans;
    }
};