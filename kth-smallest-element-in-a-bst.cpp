//  2019-7-25
//  leetcode 230题 https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//  中序遍历二叉搜索树
class Solution {
public:
    int cnt = 0, num, flag = false, result;
    
    void dfs(TreeNode* root){
        if(!root || flag)
            return;
        if(root->left)
            dfs(root->left);
        cnt++;
        if(cnt == num){
            result = root->val;
            flag = true;
            return;            
        }
        if(root->right)
            dfs(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        num = k;
        dfs(root);
        return result;
    }
};


//  暴力法
// class Solution {
// public:
//     int get_idx(vector<int> arrs, int num){      //  二分查找求索引
//         int low = 0, high = arrs.size() - 1, mid;
//         while(low <= high){
//             mid = (low + high) / 2;
//             if(arrs[mid] == num)
//                 return mid;
//             else if(arrs[mid] > num)
//                 high = mid - 1;
//             else
//                 low = mid + 1;
//         }
//         return low;
//     }
    
//     void dfs(TreeNode* root, vector<int> &arr){    //  每次将遍历到的节点按升序插入vector中
//         if(!root)
//             return;
//         if(root->left){
//             int idx = get_idx(arr, root->val);
//             arr.insert(arr.begin() + idx, root->left->val);
//             dfs(root->left, arr);
//         }
//         if(root->right){
//             int idx = get_idx(arr, root->val);
//             arr.insert(arr.begin() + idx + 1, root->right->val);
//             dfs(root->right, arr);
//         }
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> result;
//         result.push_back(root->val);
        
//         dfs(root, result);
        
//         return result[k - 1];
//     }
// };
