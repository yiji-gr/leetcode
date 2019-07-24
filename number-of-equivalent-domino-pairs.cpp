// 2019年7月21日 
// leetcode 第146场周赛  https://leetcode-cn.com/contest/weekly-contest-146/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> m;
        
        int cnt = 0;
        for(int i = 0; i < dominoes.size(); ++i){
            vector<int> v = dominoes[i];
            sort(v.begin(), v.end());
            cnt += m[v];
            m[v]++;
        }
        
        return cnt;
    }
};
