//  2019年8月3日
//  leetcode 第 583 题  https://leetcode-cn.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int dp[505][505];
        for(int i = 0; i < len1 + 1; ++i){
            for(int j = 0; j < len2 + 1; ++j){
                if(i == 0 && j == 0)
                    dp[i][j] = 0;
                else if(i == 0 && j != 0)
                    dp[i][j] = dp[i][j - 1] + 1;
                else if(j == 0 && i != 0)
                    dp[i][j] = dp[i - 1][j] + 1;
                else{
                    if(word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};

       
