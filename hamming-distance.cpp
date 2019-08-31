//  2019年8月31日
//  leetcode 第 461 题 https://leetcode-cn.com/problems/hamming-distance

// 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
// 给出两个整数 x 和 y，计算它们之间的汉明距离。

// 注意：
// 0 ≤ x, y < 231.

// 示例:
// 输入: x = 1, y = 4
// 输出: 2

// 解释:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// 上面的箭头指出了对应二进制位不同的位置。

// 执行结果：通过
// 执行用时 : 0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了78.79%的用户

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int i = 0;
        while(z != 0){		//求1的个数
            z = z & (z - 1);
            i++;
        }
        return i;
    }
};
