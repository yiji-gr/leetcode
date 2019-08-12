//  2019年8月12日 
//  leetcode第732题 https://leetcode-cn.com/problems/my-calendar-iii/

//  答案来自  https://blog.csdn.net/guo15331092/article/details/78883265
class MyCalendarThree {
public:
    map<int, int> m;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        int k = 0;
        int max_ = 0;
        m[start]++; m[end]--;
        for(auto it = m.begin(); it != m.end(); ++it){
            k += it->second;
            max_ = max(max_, k);
        }
        return max_;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
