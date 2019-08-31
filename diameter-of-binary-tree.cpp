//  2019年8月31日
//  leetcode 第 543 题 https://leetcode-cn.com/problems/diameter-of-binary-tree

// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
// 示例 :
// 给定二叉树

//           1
//          / \
//         2   3
//        / \
//       4   5
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
// 注意：两结点之间的路径长度是以它们之间边的数目表示。

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
    int max_ = 0;
    int dfs(TreeNode* rt){
        int l = 0, r = 0;
        if(rt->left != nullptr)
            l += dfs(rt->left);
        if(rt->right != nullptr)
            r += dfs(rt->right);
        if (max_ < l + r)
            max_ = l + r;
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        dfs(root);
        return max_;
    }
};
