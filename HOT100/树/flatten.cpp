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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        preorder(root);
        auto p = root;
        for (int i = 1; i < nums.size(); i++)
        {
            p->right = nums[i];
            p->left = nullptr;
            p = p->right;
        }
    }

private:
    vector<TreeNode *> nums;
    void preorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        nums.push_back(node);
        preorder(node->left);
        preorder(node->right);
    }
};