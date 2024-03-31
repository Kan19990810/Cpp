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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> res;
        int n = 1, m = 0;
        while (!q.empty())
        {
            while (n)
            {
                auto node = q.front();
                q.pop();
                n--;

                res.push_back(node->val);
                if (node->left != nullptr)
                {
                    q.push(node->left);
                    m++;
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                    m++;
                }
            }
            ans.push_back(res);
            res.clear();
            n = m;
            m = 0;
        }
        return ans;
    }
};