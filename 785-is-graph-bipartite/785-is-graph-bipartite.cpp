class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> col(v,0);
        queue<int> q;
        
        for(int i = 0;i<v;i++){
            if(col[i] == 0){
                q.push(i);
                col[i] = 1;
                while(!q.empty()){
                    int n = q.front();
                    q.pop();
                    for(auto it : graph[n]){
                        if(col[it] == 0){
                            col[it] = -col[n];
                            q.push(it);
                        }else if(col[it] == col[n]){
                            return false;                    
                        }
                    }
                }
            }    
        }
        return true;
    }
};