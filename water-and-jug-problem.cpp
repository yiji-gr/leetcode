//  2019年8月9日
//  leetcode第365题 https://leetcode-cn.com/problems/water-and-jug-problem/

class Solution {
public:
    //Stein算法 求最大公约数  https://www.cnblogs.com/drizzlecrj/archive/2007/09/14/892340.html
    int gcd(int a, int b){
        if(a==0) return b;
        if(b==0) return a;
        if((!(a&1))&&(!(b&1)))
            return 2*gcd(a>>1, b>>1);
        else if(!(a&1)) return gcd(a>>1, b);
        else if(!(b&1)) return gcd(a, b>>1);
        else
            return gcd(abs(a-b), min(a, b));
    }
    
    bool canMeasureWater(int x, int y, int z) {
        if(z==0)
            return true;
        if(x==0)
            return y==z;
        if(y==0)
            return x==z;
        if(z>(x+y))
            return false;
        int n = gcd(x, y);
        return z%n==0;
    }
};
