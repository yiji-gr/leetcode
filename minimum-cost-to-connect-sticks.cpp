//    2019年8月25日 
//    leetcode第7场双周赛第3题    https://leetcode-cn.com/contest/biweekly-contest-7/problems/minimum-cost-to-connect-sticks/

/*
为了装修新房，你需要加工一些长度为正整数的棒材 sticks。
如果要将长度分别为 X 和 Y 的两根棒材连接在一起，你需要支付 X + Y 的费用。 由于施工需要，你必须将所有棒材连接成一根。
返回你把所有棒材 sticks 连成一根所需要的最低费用。注意你可以任意选择棒材连接的顺序。

示例 1：

输入：sticks = [2,4,3]
输出：14
解释：先将 2 和 3 连接成 5，花费 5；再将 5 和 4 连接成 9；总花费为 14。
示例 2：

输入：sticks = [1,8,3,5]
输出：30
*/

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int letter[26] = {0};
        for(int i = 0; i < keyboard.length(); ++i){
            letter[keyboard[i] - 'a'] = i;
        }

        int cnt, pos;
        cnt = pos = letter[word[0] - 'a'];
        for(int i = 1; i < word.length(); ++i){
            if(word[i] == word[i - 1])
                continue;
            int cur_pos = letter[word[i] - 'a'];
            cnt += abs(pos - cur_pos);
            pos = cur_pos;
        }
        return cnt;
    }
};
