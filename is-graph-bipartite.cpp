//  2019年8月2日
//  leetcode第785题   https://leetcode-cn.com/problems/is-graph-bipartite


// ---------------栈--------------------------
// class Solution {
// public:
//     int not_in(map<int, int> m, int num){
//         for(auto it :m)
//             if(it.first == num)
//                 return false;
//         return true;
//     }
    
//     bool isBipartite(vector<vector<int>>& graph) {
//         map<int, int> visit;
//         stack<int> s;
        
//         for(int i = 0; i < graph.size(); ++i){
//             if(not_in(visit, i)){
//                 visit[i] = 1;
//                 s.push(i);
//                 while(!s.empty()){
//                     int cur = s.top();
//                     s.pop();
//                     for(int j = 0; j < graph[cur].size(); ++j){
//                         if(not_in(visit, graph[cur][j])){
//                             s.push(graph[cur][j]);
//                             visit[graph[cur][j]] = -visit[cur];
//                         }
//                         else
//                             if(visit[graph[cur][j]] == visit[cur])
//                                 return false;
//                     }
                    
//                 }
//             }
//         }
//         return true;
//     }
// };

//--------------dfs ---------------
class Solution {
public:
    bool dfs(vector<vector<int>> graph, vector<int> &color, int idx, int c){
        color[idx] = c;
        for(int i = 0; i < graph[idx].size(); ++i){
            int cur = graph[idx][i];
            if(color[cur] == c)
                return false;
            if(color[cur] == 0 && !dfs(graph, color, cur, -c)){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<int> color(num, 0);
        for(int i = 0; i < num; ++i){
            if(color[i] == 0)
                if(!dfs(graph, color, i, 1))
                    return false;
        }
        return true;
    }
};
