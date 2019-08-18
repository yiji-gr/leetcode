//  2019年8月18日
//  leetcode第59题  https://leetcode-cn.com/problems/spiral-matrix-ii/

class Solution {
public:
    enum direction{RIGHT, DOWN, LEFT, ON};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int x = 0, y = 0, cnt = n * n, state = 0;
        int x_s = 0, x_e = n - 1, y_s = 1, y_e = n - 1;
        for(int i = 0; i < cnt; ++i){
            res[y][x] = i + 1;
            if(state == RIGHT){
                if(x < x_e) x++;
                else{
                    x_e--;  state++;    y++;
                }
            }else if(state == DOWN){
                if(y < y_e) y++;
                else{
                    y_e--;  state++;    x--;
                }
                
            }else if(state == LEFT){
                if(x > x_s) x--;
                else{
                    x_s++;  state++;    y--;
                }
                
            }else if(state == ON){
                if(y > y_s) y--;
                else{
                    y_s++;  state = 0;  x++;
                }
            }
        }
        return res;
    }
};
