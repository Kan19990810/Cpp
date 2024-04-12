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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        return dfs(preorder, 0, n - 1, postorder, 0, n - 1);
    }

private:
    TreeNode *dfs(vector<int> &preorder, int preL, int preR, vector<int> &postorder, int postL, int postR)
    {
        if (preL > preR)
        {
            return nullptr;
        }
        if (preL == preR)
        {
            TreeNode *tmp = new TreeNode(preorder[preL]);
            return tmp;
        }

        int i = preL + 1;
        unordered_set<int> preSet;
        int j = postL;
        unordered_set<int> postSet;
        while (i <= preR)
        {
            preSet.insert(preorder[i]);
            postSet.insert(postorder[j]);
            bool isValid = true;
            for (auto k : preSet)
            {
                if (postSet.count(k) == 0)
                {
                    isValid = false;
                }
            }
            if (isValid)
            {
                break;
            }
            i++;
            j++;
        }

        // 前序 preL [preL + 1, i]长度: i - preL [i + 1, preR]长度 preR - i
        // 后序 [postL, J] 长度 J - postL + 1 [J + 1, postR - 1] 长度：postR - J - 1 postR

        TreeNode *node = new TreeNode(preorder[preL]);
        node->left = dfs(preorder, preL + 1, i, postorder, postL, j);
        node->right = dfs(preorder, i + 1, preR, postorder, j + 1, postR - 1);
        return node;
    }
};