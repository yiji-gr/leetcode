//    2019年8月25日 
//    leetcode第7场双周赛第1题    https://leetcode-cn.com/contest/biweekly-contest-7/problems/single-row-keyboard/

/*
我们定制了一款特殊的力扣键盘，所有的键都排列在一行上。

我们可以按从左到右的顺序，用一个长度为 26 的字符串 keyboard （索引从 0 开始，到 25 结束）来表示该键盘的键位布局。

现在需要测试这个键盘是否能够有效工作，那么我们就需要个机械手来测试这个键盘。

最初的时候，机械手位于左边起第一个键（也就是索引为 0 的键）的上方。当机械手移动到某一字符所在的键位时，就会在终端上输出该字符。

机械手从索引 i 移动到索引 j 所需要的时间是 |i - j|。

当前测试需要你使用机械手输出指定的单词 word，请你编写一个函数来计算机械手输出该单词所需的时间。
示例 1：

输入：keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
输出：4
解释：
机械手从 0 号键移动到 2 号键来输出 'c'，又移动到 1 号键来输出 'b'，接着移动到 0 号键来输出 'a'。
总用时 = 2 + 1 + 1 = 4.
示例 2：

输入：keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
输出：73
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
