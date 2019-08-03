// 2019年8月3日 
leetcode 第 279 题 https://leetcode-cn.com/problems/perfect-squares/


// --------------  动态规划 -------------
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
        for(int i = 0; i <= n; ++i)
            dp.push_back(i);
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};


// --------------- dfs --------------- 超时
// class Solution {
// public:
// 	int count = INT_MAX;
// 	void bfs(vector<int> arrs, int res, int cnt) {
// 		if (res == 0) {
// 			if (count > cnt)
// 				count = cnt;
//             return;
// 		}

// 		for (int i = arrs.size() - 1; i > -1; --i) {
// 			if (res < arrs[i])
// 				continue;
// 			cnt++;
// 			if (cnt > count)
// 				return;
// 			bfs(arrs, res - arrs[i], cnt);
// 			cnt--;
// 		}
// 	}

// 	int numSquares(int n) {
// 		vector<int> arrs;
// 		for (int i = 1; i * i <= n; ++i)
// 			arrs.push_back(i * i);

// 		bfs(arrs, n, 0);
// 		return count;
// 	}
// };
