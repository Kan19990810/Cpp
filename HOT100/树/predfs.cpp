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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 前序确认根
        int n = preorder.size();
        return dfs(preorder, 0, n - 1, inorder, 0, n - 1);
    }

private:
    TreeNode *dfs(vector<int> &preorder, int preL, int preR, vector<int> &inorder, int inL, int inR)
    {
        if (preL > preR)
        {
            return nullptr;
        }
        if (preL == preR)
        {
            TreeNode *node = new TreeNode(preorder[preL]);
            return node;
        }
        int rt = preorder[preL];
        int i = inL;
        for (; i <= inR; i++)
        {
            if (inorder[i] == rt)
            {
                break;
            }
        }
        // 中序 [inL, i - 1]  长度： i - inL i [i + 1, inR] 长度： inR - i
        // 前序 preL [preL + 1, preL + i - inL] [preL + i - inL + 1, preR] 长度 preR - preL -i + inL
        TreeNode *node = new TreeNode(rt);
        node->left = dfs(preorder, preL + 1, preL + i - inL, inorder, inL, i - 1);
        node->right = dfs(preorder, preL + i - inL + 1, preR, inorder, i + 1, inR);
        return node;
    }
};