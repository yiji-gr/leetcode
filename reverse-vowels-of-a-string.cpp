//  2019年8月12日 
//  leetcode第345题 https://leetcode-cn.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    void swap(string &s, int a, int b){
        char c = s[a]; s[a] = s[b]; s[b] = c;
    }
    
    bool judge(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
    string reverseVowels(string s) {
        int low = 0, high = s.length() - 1;
        while(low < high){
            while(low < high && !judge(s[low])) low++;
            while(low < high && !judge(s[high])) high--;
            swap(s, low, high);
            low++; high--;
        }
        return s;
    }
};
