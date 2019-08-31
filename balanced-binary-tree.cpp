//  2019年7月25日
//  leetcode第110题 https://leetcode-cn.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag = true;

    int dfs(TreeNode *root){
        if(!root)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);
        if(abs(l - r) > 1)
            flag = false;
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};
