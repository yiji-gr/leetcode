//  2019年8月3日
//  leetcode 第 64 题 https://leetcode-cn.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int cols = grid.size(), rows = grid[0].size();
        vector<vector<int>> dp(cols);
        for(int i = 0; i < cols; ++i)
            dp[i].resize(rows);
        
        dp[0][0] = grid[0][0];
        for(int i = 1; i < cols; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for(int j = 1; j < rows; ++j)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        
        for(int i = 1; i < cols; ++i){
            for(int j = 1; j < rows; ++j){
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        
        return dp[cols - 1][rows - 1];
    }
};
