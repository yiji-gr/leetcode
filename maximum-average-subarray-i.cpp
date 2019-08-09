//  2019年8月9日
//  leetcode第643题 https://leetcode-cn.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < k; ++i){
            res += nums[i];
        }
        int cur = res;
        int len = nums.size();
        for(int i = 1; i <= len - k; ++i){
            cur += nums[i + k - 1] - nums[i - 1];
            res = max(cur, res);
        }
        
        return res * 1.0 / k;
    }
};
