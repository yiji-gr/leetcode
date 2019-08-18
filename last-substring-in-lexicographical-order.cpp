//  2019年8月19日 
//  leetcode第150周周赛第4题 https://leetcode-cn.com/contest/weekly-contest-150/problems/last-substring-in-lexicographical-order/

//  c++写法 爆内存
class Solution {
public:
    string lastSubstring(string s) {
        string res = "";
        for(int i = 0; i < s.length(); ++i)
            res = max(res, s.substr(i));
        return res;
    }
};

//  python写法 ac
class Solution:
    def lastSubstring(self, s: str) -> str:
        res = ""
        for i in range(len(s)):
            res = max(res, s[i:])
            
        return res
        

// class Solution {
// public:
// 	int a[26];
// 	vector<int> get_max(vector<int> idxs, string s) {
// 		int max_idx = 0;
// 		char max_c = s[idxs[0]];
// 		vector<int> del_idxs;
// 		for (int i = 1; i < idxs.size(); ++i) {
// 			if (idxs[i] >= s.length()) {
// 				continue;
// 			}
// 			if (max_c < s[idxs[i]]) {
// 				max_idx = i;
// 				max_c = s[idxs[i]];
// 			}
// 		}

// 		for (int i = 0; i < idxs.size(); ++i) {
// 			if (s[idxs[i]] != s[idxs[max_idx]])
// 				del_idxs.push_back(i);
// 		}
// 		return del_idxs;
// 	}

// 	void del(vector<int> &idxs, vector<int> del_idxs) {
// 		int del_num = 0;
// 		for (int i = 0; i < del_idxs.size(); ++i) {
// 			idxs.erase(idxs.begin() + del_idxs[i] - del_num);
// 			del_num++;
// 		}
// 	}

// 	void update(vector<int> &idxs) {
// 		for (int i = 0; i < idxs.size(); ++i)
// 			idxs[i]++;
// 	}

// 	string lastSubstring(string s) {
//         string aaa = "ac";
//         string bbb = "abc";
//         cout << (aaa > bbb) << endl;
        
// 		memset(a, 0, sizeof(a));
// 		for (auto c : s) {
// 			a[c - 'a']++;
// 		}
// 		int idx = 0;
// 		for (int i = 25; i >= 0; --i) {
// 			if (a[i] != 0) {
// 				idx = i;
// 				break;
// 			}
// 		}
// 		vector<int> idxs;
// 		for (int i = 0; i < s.length(); ++i) {
// 			if (i < s.length() - 1 && s[i] == (idx + 'a'))
// 				if((i > 0 && s[i - 1] != (idx + 'a')) || i == 0)
// 					idxs.push_back(i + 1);
// 		}
// 		if (idxs.size() == 0) {
// 			return s.substr(s.length() - 1);
// 		}

// 		vector<int> del_idxs;
// 		int del_num = 0;
// 		while (idxs.size() > 1) {
// 			del_idxs = get_max(idxs, s);
// 			if(del_idxs.size() != 0)
// 				del(idxs, del_idxs);
// 			update(idxs);
// 			del_num++;
// 		}

// 		return s.substr(idxs.back() - del_num - 1);
// 	}
// };
