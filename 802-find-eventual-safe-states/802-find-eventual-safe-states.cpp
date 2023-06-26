class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        int inDeg[v];
        memset(inDeg,0,v*sizeof(int));    
        vector<int> adjRev[v];
        
        for(int i = 0;i<v;i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                inDeg[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        
        for(int i = 0;i<v;i++){
            if(!inDeg[i]){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            safeNodes.push_back(n);
            for(auto it: adjRev[n]){
                inDeg[it]--;
                if(!inDeg[it]){
                    q.push(it);
                }
            }            
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};