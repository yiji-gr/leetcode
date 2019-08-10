//  2019年8月10日
//  leetcode第1018题  https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int cur = 0;
        for(int i = 0; i < A.size(); ++i){
            cur = ((cur<<1) + A[i]) % 5;
            res.push_back(cur==0);
        }
        return res;
    }
};
