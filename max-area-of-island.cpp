// 2019年8月3日
// leetcode 第 695 题 https://leetcode-cn.com/problems/max-area-of-island

class Solution {
public:
	int direct[4][2] = { { 1, 0 },{ 0, 1 },{ 0, -1 },{ -1, 0 } };
	int cnt = 0;

	bool out_(int i, int j, int cols, int rows) {
		if (i < 0 || j < 0 || i >= cols || j >= rows)
			return true;
		return false;
	}

	void bfs(vector<vector<int>> grid, queue<pair<int, int>> &q, vector<vector<int>> &visit) {
		int cols = grid.size(), rows = grid[0].size();
		int num = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();

			num++;
			cnt = max(cnt, num);
			for (int i = 0; i < 4; ++i) {
				int cur_x = direct[i][0] + x, cur_y = direct[i][1] + y;
				if (out_(cur_x, cur_y, cols, rows))
					continue;
				if (!grid[cur_x][cur_y])
					continue;
				if (visit[cur_x][cur_y])
					continue;
				visit[cur_x][cur_y] = 1;
				q.push(make_pair(cur_x, cur_y));
			}
		}
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<vector<int>> visit;
		for (int i = 0; i < grid.size(); ++i) {
			vector<int> tmp;
			for (int j = 0; j < grid[i].size(); ++j) {
				tmp.push_back(0);
			}
			visit.push_back(tmp);
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 1 && !visit[i][j]) {
					visit[i][j] = 1;
					q.push(make_pair(i, j));
					bfs(grid, q, visit);
				}
			}
		}

		return cnt;
	}
};
