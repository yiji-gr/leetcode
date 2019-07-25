//  2019年7月25日 
//  leetcode第513题 https://leetcode-cn.com/problems/find-bottom-left-tree-value/

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
    int num, d = 0;
    
    void dfs(TreeNode* root, int depth){
        if(!root)
            return;
        
        if(depth > d){
            num = root->val;
            d = depth;
        }
        
        if(root->left)
            dfs(root->left, depth + 1);
        if(root->right)
            dfs(root->right, depth + 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        
        return num;
    }
};
