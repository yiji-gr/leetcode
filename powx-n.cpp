//  2019年8月6日
//  leetcode第50题  https://leetcode-cn.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double res=1.;
        int m=n;
        while(n!=0){
            if(n&1)
                res*=x;
            x*=x;
            n/=2;
        }
        return m<0?(1./res):res;
    }
};
