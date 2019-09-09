//  2019年9月9日
//  leetcode 第 236 题 https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree

// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 示例 1:
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出: 3
// 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

// 示例 2:
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// 输出: 5
// 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。

// 说明:
// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉树中。

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
    bool dfs(TreeNode* root, vector<TreeNode*> &path, TreeNode* p){
        if(root == nullptr)
            return false;
        path.emplace_back(root);
        if(root == p)
            return true;
        if(dfs(root->left, path, p))
            return true;
        if(dfs(root->right, path, p))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        dfs(root, path1, p);
        dfs(root, path2, q);
        int i;
        for(i = 0; i < min(path1.size(), path2.size()); ++i){
            if(path1[i] != path2[i])
                break;
        }
        return path1[i - 1];
    }
};
