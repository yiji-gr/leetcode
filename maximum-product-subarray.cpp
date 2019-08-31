//  2019年8月12日
//  leetcode第152题 https://leetcode-cn.com/problems/maximum-product-subarray/

// 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

// 示例 1:
// 输入: [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。

// 示例 2:
// 输入: [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_ = 1, max_ = 1, res = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0){
                int tmp = min_;
                min_ = max_;
                max_ = tmp;
            }
            min_ = min(nums[i], min_ * nums[i]);
            max_ = max(nums[i], max_ * nums[i]);
            res = max(max_, res);
        }
        return res;
    }
};
