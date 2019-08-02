# 2019年8月2日
# leetcode 207题   https://leetcode-cn.com/problems/course-schedule/

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		map<int, vector<int>> m;
		vector<int> indegree;
		for (int i = 0; i < numCourses; ++i) {
			indegree.push_back(0);
			vector<int> tmp;
			m[i] = tmp;
		}

		for (int i = 0; i < prerequisites.size(); i++) {
			for (int j = 1; j < prerequisites[i].size(); ++j) {
				m[prerequisites[i][0]].push_back(prerequisites[i][j]);
				indegree[prerequisites[i][j]]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < indegree.size(); ++i) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		int cnt = 0;
		while (!q.empty()) {
			int cur = q.front();
			for (int i = 0; i < m[cur].size(); ++i) {
				indegree[m[cur][i]]--;
				if (indegree[m[cur][i]] == 0)
					q.push(m[cur][i]);
			}
			cnt++;
			q.pop();
		}

		return cnt == numCourses;
	}
};
