//    2019年8月24日
//    leetcode第322题	https://leetcode-cn.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        for (int i = 0; i <= amount; ++i)
            dp.push_back(amount + 1);

        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (int i = coins[0]; i <= amount; ++i) {
            for (int j = 0; j < coins.size() && i >= coins[j]; ++j) {
                if (dp[i - coins[j]] == amount + 1)
                    continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        return dp[amount] != (amount + 1) ? dp[amount] : -1;
    }
};
