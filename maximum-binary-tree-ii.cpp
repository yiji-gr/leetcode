//  2019年8月12日
//  leetcode第998题 https://leetcode-cn.com/problems/maximum-binary-tree-ii/

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* cur = new TreeNode(val);
        if(root == nullptr)
            return cur;
        if(val > root->val){
            cur->left = root;
            return cur;
        }
        
        TreeNode* tmp = root;
        while(tmp->right != nullptr && tmp->right->val > val){
            tmp = tmp->right;
        }
        if(tmp->right == nullptr){
            tmp->right = cur;
        }else{
            cur->left = tmp->right;
            tmp->right = cur;
        }
        return root;
    }
};
