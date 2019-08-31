//  2019年8月13日
//  leetcode第473题  https://leetcode-cn.com/problems/matchsticks-to-square/

// 还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，
// 请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，
// 可以把火柴连接起来，并且每根火柴都要用到。
// 输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

// 示例 1:
// 输入: [1,1,2,2,2]
// 输出: true
// 解释: 能拼成一个边长为2的正方形，每边两根火柴。

// 示例 2:
// 输入: [3,3,3,3,4]
// 输出: false
// 解释: 不能用所有火柴拼成一个正方形。

class Solution {
public:
	bool dfs(vector<int> nums, vector<int> &visit, int idx, long long sum, long long avg) {
		visit[idx] = 1;
		if (sum == avg) {
			return true;
		}
		for (int i = idx + 1; i < nums.size(); ++i) {
			if (visit[i] || sum + nums[i] > avg)  continue;
			sum += nums[i];
			if (dfs(nums, visit, i, sum, avg))  return true;
			visit[i] = 0;
			sum -= nums[i];
		}
		return false;
	}

	bool makesquare(vector<int>& nums) {
		if(nums.size() < 4)
      		return false;
		long long sum = 0;
		for (auto it : nums)
			sum += it;
		if (sum % 4 != 0)
			return false;
		sum /= 4;

		sort(nums.rbegin(), nums.rend());
		if (nums[0] > sum) return false;

		vector<int> visit(nums.size());
		int cnt = 4;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0) visit[i] = 1;
			if (visit[i]) continue;
			if (dfs(nums, visit, i, nums[i], sum))
				cnt--;
		}
		return cnt == 0;
	}
};
