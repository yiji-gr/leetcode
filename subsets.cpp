//  2019年8月12日
//  leetcode第78题  https://leetcode-cn.com/problems/subsets/

//  https://www.cnblogs.com/ariel-dreamland/p/9154503.html
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    
    void dfs(vector<int> nums, int idx){
        if(idx <= nums.size()){
            res.push_back(tmp);
        }
        for(int i = idx; i < nums.size(); ++i){
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};
