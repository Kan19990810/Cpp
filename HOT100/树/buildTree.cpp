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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        return dfs(inorder, 0, n - 1, postorder, 0, n - 1);
    }

private:
    TreeNode *dfs(vector<int> &inorder, int inL, int inR, vector<int> &postorder, int postL, int postR)
    {
        if (inL > inR)
        {
            return nullptr;
        }
        if (inL == inR)
        {
            TreeNode *tmp = new TreeNode(inorder[inL]);
            return tmp;
        }

        int rt = postorder[postR];
        int i = inL;
        for (; i <= inR; i++)
        {
            if (inorder[i] == rt)
            {
                break;
            }
        }

        // 中序 [inL, i - 1] 长度:i-inL  i  [i + 1, inR] 长度：inR - i
        // 后续 [postL, postL + i - inL - 1 ] [postL + i - inL , postR - 1]长度：postR - postL - i + inL postR

        TreeNode *node = new TreeNode(inorder[i]);
        node->left = dfs(inorder, inL, i - 1, postorder, postL, postL + i - inL - 1);
        node->right = dfs(inorder, i + 1, inR, postorder, postL + i - inL, postR - 1);
        return node;
    }
};