//  2019年8月31日
//  leetcode 第 819 题 https://leetcode-cn.com/problems/most-common-word

// 给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。题目保证至少有一个词不在禁用列表中，而且答案唯一。
// 禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。

// 示例：
// 输入:
// paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
// banned = ["hit"]
// 输出: "ball"
// 解释:
// "hit" 出现了3次，但它是一个禁用的单词。
// "ball" 出现了2次 (同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。
// 注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"），
// "hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。

class Solution {
public:
    vector<string> str2vec(string str){
        vector<string> strs;
        for(int i = 0; i < str.length(); ){
            string tmp = "";
            while(str[i] >= 'a' && str[i] <= 'z'){
                tmp += str[i];
                i++;
            }
            strs.push_back(tmp);
			while (i < str.length() && (str[i] < 'a' || str[i] > 'z'))
                i++;
        }
        return strs;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        map<string, int> m1, m2;
        for(auto str: banned)
            m2[str]++;

        vector<string> strs = str2vec(paragraph);
        for(auto str: strs)
            if(m2[str] == 0)
                m1[str]++;
        string res;
        int max_ = 0;
        for(auto it: m1){
            if(max_ < it.second){
                max_ = it.second;
                res = it.first;
            }
        }
        return res;
    }
};
