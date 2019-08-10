//  2019年8月10日
//  leetcode第453题 https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/

//	原题理解为每次除了最大的元素，其余元素均+1。换种角度即是每次最大元素-1，减到所有元素都等于最小元素为止
//	答案为所有元素减去最小元素之和

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_idx = 0, min_v = nums[0];
        int len = nums.size();
        for(int i = 0; i < len; ++i){         
            if(nums[i] < min_v){
                min_v = nums[i];
                min_idx = i;
            }
        }
        
        int total = 0;
        for(int i = 0; i < nums.size(); ++i){
            total += nums[i] - nums[min_idx];
        }
        return total;
    }
};
