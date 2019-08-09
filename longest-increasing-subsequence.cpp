//2019年7月24日
//leetcode第300题 https://leetcode-cn.com/problems/longest-increasing-subsequence/

//O(n2)解法   简单的动态规划  双重循环
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        
        vector<int> dp;
        for(int i = 0; i < len; ++i)
            dp.push_back(1);
        
        for(int i = 0; i < len - 1; ++i){
            for(int j = i + 1; j < len; ++j){
                if(nums[j] > nums[i])
                    dp[j] = max(dp[i] + 1, dp[j]);
            }
        }
        
        int max_ = dp[0];
        for (int i = 1; i < len; ++i){
            if(max_ < dp[i])
                max_ = dp[i];
        }
        
        return max_;
    }
};

//-----------------------------------------------------------------

//O(n log n)解法
class Solution {
public:
    int f(vector<int> &seq, int num){     // 用二分查找的方法插入替换原序列中的元素
        int low = 0, high = seq.size() - 1, mid = 0;
        while(low <= high){
            mid = (low + high) / 2;
            if(seq[mid] > num)
                high = mid - 1;
            else if(seq[mid] < num)
                low = mid + 1;
            else                        // 查找到相同值直接返回，未对序列进行修改
                return 0;
        }
        if(seq[mid] < num)
            seq[mid + 1] = num;
        else
            seq[mid] = num;
        return 0;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i = 1; i < len; ++i){   //遍历整个vector。每次对新的元素操作
            if(nums[i] > seq.back())
                seq.push_back(nums[i]);
            else if(nums[i] < seq.back())
                f(seq, nums[i]);
        }
        return seq.size();
    }
};
