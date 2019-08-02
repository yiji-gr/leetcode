//  2019年8月2日
//  leetcode第785题   https://leetcode-cn.com/problems/is-graph-bipartite

class Solution {
public:
    int not_in(map<int, int> m, int num){
        for(auto it :m)
            if(it.first == num)
                return false;
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, int> visit;
        stack<int> s;
        
        for(int i = 0; i < graph.size(); ++i){
            if(not_in(visit, i)){
                visit[i] = 1;
                s.push(i);
                while(!s.empty()){
                    int cur = s.top();
                    s.pop();
                    for(int j = 0; j < graph[cur].size(); ++j){
                        if(not_in(visit, graph[cur][j])){
                            s.push(graph[cur][j]);
                            visit[graph[cur][j]] = -visit[cur];
                        }
                        else
                            if(visit[graph[cur][j]] == visit[cur])
                                return false;
                    }
                    
                }
            }
        }
        return true;
    }
};
