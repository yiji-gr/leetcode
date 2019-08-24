//    2019年8月24日
//    leetcode第42题	https://leetcode-cn.com/problems/trapping-rain-water

class Solution {
public:
    int f(vector<int> height, int idx) {
        int start = height.size() - 1;
        while (start > idx && height[start] == 0)
            start--;
        int sum = 0;
        while (start > idx) {
            int num = 0, i;
            bool flag = false;
            for (i = start - 1; i >= idx; --i) {
                if (height[i] >= height[start]) {
                    start = i;
                    flag = true;
                    break;
                }
                num += height[start] - height[i];
            }
            if (flag)
                sum += num;
            else
                break;
        }
        return sum;
    }

    int trap(vector<int>& height) {
        int low = 0, high = height.size();
        while (low < high && height[low] == 0)
            low++;
        int sum = 0;

        while (low < high) {
            int num = 0, i;
            bool flag = false;
            for (i = low + 1; i < high; ++i) {
                if (height[i] >= height[low]) {
                    low = i;
                    flag = true;
                    break;
                }
                num += height[low] - height[i];
            }
            if (flag)
                sum += num;
            else {
                sum += f(height, low);
                break;
            }
        }
        return sum;
    }
};
