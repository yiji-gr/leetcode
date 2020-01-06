//  2020年1月6日
//  leetcode第5题 https://leetcode-cn.com/problems/longest-palindromic-substring/

// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。

// 示例 2：
// 输入: "cbbd"
// 输出: "bb"

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len == 0)
			return s;
		int max_ = 0, low = 0, high = 0;
		vector<vector<int>> dp(len, vector<int>(len));
		vector<vector<int>> dp1(len, vector<int>(len));
		for (int i = 0; i < len; ++i) {
			dp[i][i] = 1;
			if (i > 0 && s[i] == s[i - 1]) {
				dp1[i - 1][i] = 2;
				low = i - 1, high = i;
			}
		}
		for (int i = 0; i < len; ++i) {
			for (int j = 1; (i - j >= 0) && (i + j < len); ++j) {
				if (s[i - j] != s[i + j])
					break;
				dp[i - j][i + j] = dp[i - j + 1][i + j - 1] + 2;
				if (dp[i - j][i + j] > max_) {
					max_ = dp[i - j][i + j];
					low = i - j, high = i + j;
				}
			}
			if (i > 0 && s[i] == s[i - 1]) {
				for (int j = 1; (i - 1 - j >= 0) && (i + j < len); ++j) {
					if (s[i - 1 - j] != s[i + j])
						break;
					dp1[i - 1 - j][i + j] = dp1[i - j][i + j - 1] + 2;
					if (dp1[i - 1 - j][i + j] > max_) {
						max_ = dp1[i - 1 - j][i + j];
						low = i - 1 - j, high = i + j;
					}
				}
			}
		}
		return s.substr(low, high - low + 1);
	}
};
