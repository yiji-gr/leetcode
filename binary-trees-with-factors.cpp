//  2019年8月12日
//  leetcode第823题  https://leetcode-cn.com/problems/binary-trees-with-factors/

const int mol = 1000000007;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int len = A.size();
        sort(A.begin(), A.end());
        map<int, long> dp;
        for(int i = 0; i < len; ++i){
            dp[A[i]] = 1;
            for(int j = 0; j < i; ++j){
                if(A[i] % A[j] == 0)    //这里会执行两遍 eg. 8=2*4 && 8=4*2
                    dp[A[i]] = (dp[A[i]] + (dp[A[j]] * dp[A[i] / A[j]] % mol)) % mol;
            }
        }
        
        int sum = 0;
        for(auto i: dp){
            sum += i.second; sum %= mol;
        }
        return sum;
    }
};
