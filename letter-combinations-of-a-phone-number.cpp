// 2019年8月3日 
//leetcode 第 17 题https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<vector<char>> strs = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, 
                             {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    
    void dfs(vector<string> &res, string digits, string str, int idx){
        if(idx == digits.length()){
            res.push_back(str);
            return;
        }

        int num = digits[idx] - '0';
        for(int i = 0; i < strs[num].size(); ++i){
            str += strs[num][i];
            dfs(res, digits, str, idx + 1);
            str = str.substr(0, str.length() - 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits == "")
            return result;
        dfs(result, digits, "", 0);
        
        return result;
    }
};
