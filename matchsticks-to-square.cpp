//  2019年8月13日 
//  leetcode第473题  https://leetcode-cn.com/problems/matchsticks-to-square/

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
