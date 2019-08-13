//  2019年8月13日 
//  leetcode第697题 https://leetcode-cn.com/problems/degree-of-an-array/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        map<int, vector<int>> m;
        map<int, int> visit;
        
        for(int i = 0; i < len; ++i){
            if(visit[nums[i]]){
                m[nums[i]][0]++;
                m[nums[i]][2] = i - m[nums[i]][1] + 1;
            }else{
                visit[nums[i]] = 1;
                vector<int> v = {1, i, 1};
                m[nums[i]] = v;
            }
        }
        
        int degree = 0, min_len = len;
        for(auto i: m){
            if(degree < i.second[0]){
                degree = i.second[0];
                min_len = i.second[2];
            }else if(degree == i.second[0]){
                min_len = min(min_len, i.second[2]);
            }
        }
        return min_len;
    }
};
