/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // 找到最近的公共祖先，需要从叶子节点开始遍历，使用success标识是否已经找到p 或者 q
    // 使用全局变量找到最近公共祖先
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }

private:
    TreeNode *ans = nullptr;
    bool dfs(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == nullptr)
        {
            return false;
        }

        bool l = dfs(node->left, p, q);
        bool r = dfs(node->right, p, q);

        if (l && r)
        {
            // cout << "1 " << node->val << endl;
            ans = node;
            return true;
        }

        if ((l || r) && (node->val == p->val || node->val == q->val))
        {
            // cout << "2 " << node->val << endl;
            ans = node;
            return true;
        }
        return l || r || (node->val == p->val) || (node->val == q->val);
    }
};