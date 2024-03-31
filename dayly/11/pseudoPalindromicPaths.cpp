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
    // 回溯
    int pseudoPalindromicPaths(TreeNode *root)
    {
        // counter 函数全局
        vector<int> counter(10);
        return dfs(root, counter);
    }

    int dfs(TreeNode *root, vector<int> &counter)
    {
        if (root == nullptr)
        {
            return 0;
        }
        counter[root->val]++;
        int res = 0;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (isPesudo(counter))
            {
                res = 1;
            }
        }
        else
        {
            res = dfs(root->left, counter) + dfs(root->right, counter);
        }
        counter[root->val]--;
        return res;
    }

    bool isPesudo(const vector<int> &counter)
    {
        int odd = 0;
        for (int value : counter)
        {
            if (value & 1 == 1)
            {
                odd++;
            }
        }
        return odd <= 1;
    }
};