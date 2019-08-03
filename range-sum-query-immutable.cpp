//  2019年8月3日
//  leetcode 第 303 题  https://leetcode-cn.com/problems/range-sum-query-immutable/

class NumArray {
public:
    vector<int> arrs;     // 前缀和
    
    NumArray(vector<int>& nums) {
        arrs.resize(nums.size() + 1);
        arrs[0] = 0;
        int t = 0;
        for(int i = 0; i < nums.size(); ++i){
            t += nums[i];
            arrs[i + 1] = t;
        }
    }
    
    int sumRange(int i, int j) {
        return arrs[j + 1] - arrs[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
