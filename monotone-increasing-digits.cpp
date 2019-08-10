//  2019年8月10日
//  leetcode第738题 https://leetcode-cn.com/problems/monotone-increasing-digits/

class Solution {
public:
	int times(int n) {
		int total = 1;
		for (int i = 0; i < n; ++i)
			total *= 10;
		return total;
	}

	int monotoneIncreasingDigits(int N) {
		if (N < 10)
			return N;
		vector<int> nums;
		while (N != 0) {
			nums.push_back(N % 10);
			N /= 10;
		}

		int idx = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums[i] < nums[i + 1]) {
				idx = i + 1;
				nums[i + 1]--;
			}
		}

		for (int i = 0; i < idx; ++i) {
			nums[i] = 9;
		}

		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
			res += times(i) * nums[i];
		return res;
	}
};
