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
class FindElements
{
private:
    unordered_set<int> numSet;

public:
    FindElements(TreeNode *root)
    {
        function<void(TreeNode * subRoot)> dfs = [&](TreeNode *subRoot)
        {
            if (subRoot == root)
            {
                subRoot->val = 0;
                numSet.emplace(subRoot->val);
            }
            if (subRoot->left != nullptr)
            {
                subRoot->left->val = subRoot->val * 2 + 1;
                numSet.emplace(subRoot->left->val);
                dfs(subRoot->left);
            }
            if (subRoot->right != nullptr)
            {
                subRoot->right->val = subRoot->val * 2 + 2;
                numSet.emplace(subRoot->right->val);
                dfs(subRoot->right);
            }
        };

        dfs(root);
    }

    bool find(int target)
    {
        return numSet.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */