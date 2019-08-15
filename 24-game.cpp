//  2019年8月13日 
//  leetcode第679题 https://leetcode-cn.com/problems/24-game/

//---------更简练的深搜-------------  但是忽略了一种情况 (a+b)*(c-d) (a+b)/(c-d) 两边加减中间乘除的情况 没有ac
string ops = "+-/*";
string st;
const float eps = 0.001;

bool dfs(vector<int> nums, vector<int> &visit, float cur, int cnt, string &s) {
	if (cnt == 3) {
		return abs(cur - 24) < eps;
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			for (int j = 0; j < ops.length(); ++j) {
				if (ops[j] == '+') {
					s = '(' + s + '+' + static_cast<char>(nums[i] + '0') + ')';
					if (dfs(nums, visit, cur + nums[i], cnt + 1, s))
						return true;
					s = s.substr(1);	s.pop_back(); s.pop_back(); s.pop_back();
				}
				else if (ops[j] == '-') {
					s = '(' + s + '-' + static_cast<char>(nums[i] + '0') + ')';
					if (dfs(nums, visit, cur - nums[i], cnt + 1, s))
						return true;
					s = s.substr(1);  s.pop_back();	s.pop_back();	s.pop_back();
					
					s.insert(0, 1, '('); s.insert(0, 1, '-');	s.insert(0, 1, (nums[i] + '0')); s.push_back(')');
					if (dfs(nums, visit, nums[i] - cur, cnt + 1, s))
						return true;
					s = s.substr(3);	s.pop_back();
				}
				else if (ops[j] == '*') {
					s = '(' + s + '*' + static_cast<char>(nums[i] + '0') + ')';
					if (dfs(nums, visit, nums[i] * cur, cnt + 1, s))
						return true;
					s = s.substr(1);  s.pop_back();	s.pop_back(); s.pop_back();
				}
				else if (ops[j] == '/') {
					s = '(' + s + '/' + static_cast<char>(nums[i] + '0') + ')';
					if (nums[i] != 0 && dfs(nums, visit, cur / nums[i], cnt + 1, s))
						return true;
					s = s.substr(1); s.pop_back();	s.pop_back();	s.pop_back();
					
					s.insert(0, 1, '/'); s.insert(0, 1, (nums[i] + '0')); s.insert(0, 1, '(');   s.push_back(')');
					if (cur != 0 && dfs(nums, visit, nums[i] / cur, cnt + 1, s))
						return true;
					s = s.substr(3);	s.pop_back();
				}
				else
					throw "no this op";
			}
			visit[i] = 0;
		}
	}
	return false;
}

bool f(vector<int> nums) {
	for (int i = 0; i < 4; ++i) {
		vector<int> visit(4, 0);
		visit[i] = 1;
		st += (nums[i] + '0');
		if (dfs(nums, visit, nums[i] * 1.f, 0, st)) {
			cout << st << endl;
			return true;
		}
	}
	return false;
}

//直接枚举出所有可能的字符串表达式 然后计算值  时空复杂度过高 ac
class Solution {
public:
	string ops = "+-*/";
	vector<vector<int>> bracket_idxs = { { 0, 4, 6, 7 },{ 0, 4 },{ 0, 6 },{ 2, 6 },{ 2, 7 },{ 4, 7 } };   //插入括号的索引
	vector<int> visit = { 0,0,0,0 };    //4个数是否访问到

	string v2s(vector<int> arrs) {
		string s = "";
		for (auto it : arrs)
			s += ('0' + it);
		return s;
	}

	vector<string> add_bracket(string s) {    //给包含*、/的表达式加括号
		vector<string> strs;
		for (int i = 0; i < 6; ++i) {
			string tmp = s;
			vector<int> bracket_idx = bracket_idxs[i];
			for (int i = 0; i < bracket_idx.size(); ++i) {
				if (bracket_idx[i] == 7) {
					tmp.push_back(')');
					break;
				}
				if (i & 1) tmp.insert(tmp.begin() + bracket_idx[i], ')');
				else tmp.insert(tmp.begin() + bracket_idx[i], '(');
			}
			strs.push_back(tmp);
		}
		return strs;
	}

	float cal_string(string s) {    //计算表达式的值
		vector<float> num; string ops;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				int r = i + 1;
				while (s[r] != ')')	r++;
				num.push_back(cal_string(s.substr(i + 1, r - i - 1)));
				i = r;
			}
			else if (s[i] >= '1' && s[i] <= '9') {
				num.push_back((s[i] - '0') * 1.f);
			}
			else {
				ops.push_back(s[i]);
			}
		}

		return get_num(num, ops);
	}

	float get_num(vector<float> num, string ops) {  
		vector<float> arr = { num[0] }; string s = "";
		for (int i = 0; i < ops.length(); ++i) {    //先乘除
			if (ops[i] == '/') {
				if (num[i + 1] != 0)
					arr.back() /= num[i + 1];
				else
					arr.back() = 100;
			}
			else if (ops[i] == '*') {
				arr.back() *= num[i + 1];
			}
			else {
				arr.push_back(num[i + 1]);
				s += ops[i];
			}
		}

		float res = arr[0];
		for (int i = 0; i < s.length(); ++i) {  // 后加减
			if (s[i] == '+') {
				res += arr[i + 1];
			}
			else {
				res -= arr[i + 1];
			}
		}
		return res;
	}

	bool search(string s) {   
		auto pos1 = s.find('/'), pos2 = s.find('*');
		return (pos1 == s.npos) && (pos2 == s.npos);
	}

	bool dfs(vector<string> v, string s, int idx) {
		if (idx == 7) {   //4个数和3个操作符
			if (search(s)) {
				return abs(cal_string(s) - 24.f) < 0.001;
			}
			vector<string> strs = add_bracket(s);
			for (auto str : strs) {
				if (abs(cal_string(str) - 24.f) < 0.001)
					return true;
			}
			return false;
		}
		for (int i = 0; i < v[idx].length(); ++i) {
			if (idx % 2 == 0) {   //插入数字不重复
				if (visit[i])
					continue;
				visit[i] = 1;
			}
			s.push_back(v[idx][i]);
			if (dfs(v, s, idx + 1)) return true;
			s.pop_back();
			if (idx % 2 == 0)
				visit[i] = 0;
		}
		return false;
	}

	// (1+(2)+(3)+4)
	// (1+2)+(3+4)    (1+2+3)+4    (1+2)+3+4    1+(2+3)+4    1+(2+3+4)    1+2+(3+4)
	bool judgePoint24(vector<int>& nums) {
		string str_num = v2s(nums);
		vector<string> v = { str_num, ops, str_num, ops, str_num, ops, str_num };
		return dfs(v, "", 0);
	}
};
