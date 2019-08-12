//  2019年8月12日 
//  leetcode第1137题  https://leetcode-cn.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1, t;
        for(int i = 3; i <= n; ++i){
            t = t0 + t1 + t2;
            t0 = t1; t1 = t2; t2 = t;
        }
        return t;
    }
};
