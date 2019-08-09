//2019年7月21日
//leetcode 654题 https://leetcode-cn.com/problems/maximum-binary-tree/

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
    int get_max(vector<int> nums, int low, int high){
        int max_ = nums[low], idx = low;
        for(int i = low + 1; i < high; ++i){
            if(nums[i] > max_){
                max_ = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    
    TreeNode* get(vector<int> nums, int low, int high){
        if(low == high)
            return NULL;
        int max_idx = get_max(nums, low, high);
        TreeNode* tr = new TreeNode(nums[max_idx]);
        
        tr->left = get(nums, low, max_idx);
        tr->right = get(nums, max_idx + 1, high);
        
        return tr;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return get(nums, 0, nums.size());
    }
};
