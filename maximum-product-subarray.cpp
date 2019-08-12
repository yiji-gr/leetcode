//  2019年8月12日
//  leetcode第152题 https://leetcode-cn.com/problems/maximum-product-subarray/

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
