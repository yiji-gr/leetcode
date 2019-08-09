// 2019年8月9日
// leetcode第1071题 https://leetcode-cn.com/problems/greatest-common-divisor-of-stringsclass Solution {
public:
	vector<int> gcd(int x, int y) {
		vector<int> res;
		for (int i = 1; i <= min(x, y); ++i) {
			if (x % i == 0 && y % i == 0)
				res.push_back(i);
		}
		return res;
	}

	bool test(string str, string s) {
		int len1 = str.length(), len2 = s.length();
		for (int i = 0; i < len1 / len2; i += len2) {
			if (str.substr(i, len2) != s)
				return false;
		}
		return true;
	}

	string gcdOfStrings(string str1, string str2) {
		int len1 = str1.length(), len2 = str2.length();
        cout << len1 << " " << len2 << endl;
		vector<int> gcds = gcd(len1, len2);

		int idx = 0;
		for (int i = gcds.size() - 1; i >= 0; --i) {
			string s = str1.substr(0, gcds[i]);
			if (test(str1, s) && test(str2, s)) {
				idx = gcds[i];
				break;
			}
		}
		return str1.substr(0, idx);
	}
};

