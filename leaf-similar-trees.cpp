//  2019年8月10日
//  leetcode第872题 https://leetcode-cn.com/problems/leaf-similar-trees/

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
    void get_leaf(TreeNode* rt, vector<int>& leafs) {
        if(nullptr == rt)    
            return;
        if(rt->left == nullptr && rt->right == nullptr)
            leafs.push_back(rt->val);
        get_leaf(rt->left, leafs);
        get_leaf(rt->right, leafs);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2; 
        get_leaf(root1, leafs1);
        get_leaf(root2, leafs2);
        
        return leafs1 == leafs2;
    }
};
