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
    // 原来是用栈进行模拟 ， 先进后出， 进去的都是中间节点，所以看处理顺序
    vector<int> inorderTraversal(TreeNode *root)
    {
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
            ans.push_back(node->val);
            node = node->right;
        }
        return ans;
    }

private:
    vector<int> ans;
    stack<TreeNode *> stk;
};