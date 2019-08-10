//  2019年8月10日
//  leetcode第935题 https://leetcode-cn.com/problems/knight-dialer/

class Solution {
public:
	int knightDialer(int N) {
		vector<vector<long long>> dp(10, vector<long long>(N));
		int x = 1000000007;
		for (int i = 0; i < 10; ++i)
			dp[i][0] = 1;
		for (int i = 1; i < N; ++i) {
			dp[0][i] = dp[4][i - 1] + dp[6][i - 1];
			dp[1][i] = dp[6][i - 1] + dp[8][i - 1];
			dp[2][i] = dp[7][i - 1] + dp[9][i - 1];
			dp[3][i] = dp[4][i - 1] + dp[8][i - 1];
			dp[4][i] = dp[0][i - 1] + dp[3][i - 1] + dp[9][i - 1];
			dp[6][i] = dp[0][i - 1] + dp[1][i - 1] + dp[7][i - 1];
			dp[7][i] = dp[2][i - 1] + dp[6][i - 1];
			dp[8][i] = dp[1][i - 1] + dp[3][i - 1];
			dp[9][i] = dp[2][i - 1] + dp[4][i - 1];
			for (int j = 0; j < 10; ++j)
				dp[j][i] %= x;
		}

		int res = 0;
		for (int i = 0; i < 10; ++i) {
			res += dp[i][N - 1];
			res %= x;
		}
		return res;
	}
};
