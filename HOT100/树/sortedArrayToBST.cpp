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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        return dfs(nums, 0, n - 1);
    }

private:
    TreeNode *dfs(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) >> 1;
        TreeNode *node = new TreeNode(nums[mid]);
        TreeNode *leftNode = dfs(nums, left, mid - 1);
        TreeNode *rightNode = dfs(nums, mid + 1, right);
        node->left = leftNode;
        node->right = rightNode;
        return node;
    }
};