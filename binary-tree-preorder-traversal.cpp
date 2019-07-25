//  2019年7月25日
//  leetcode第144题 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//递归
// class Solution {
// public:
//     void dfs(TreeNode* root, vector<int> &arrs){
//         if(!root)
//             return;
//         arrs.push_back(root->val);
//         if(root->left)
//             dfs(root->left, arrs);
//         if(root->right)
//             dfs(root->right, arrs);
//     }
    
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         dfs(root, result);
//         return result;
//     }
// };

//非递归  栈
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;

        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *tmp = q.top();
            result.push_back(tmp->val);
            q.pop();
            
            if(tmp->right)
                q.push(tmp->right);
            if(tmp->left)
                q.push(tmp->left);
        }
        
        return result;
    }
};
