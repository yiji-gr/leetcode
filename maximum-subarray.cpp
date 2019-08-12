//  2019年8月12日
//  leetcode第53题  https://leetcode-cn.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            res = max(res, sum);
        }
        return res;
    }
};
