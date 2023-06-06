class Solution {
private:
        void dfs(int node, vector<int> adj[], int vis[]){
            vis[node] = 1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis);
                }
            }
        }
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
            int cnt = 0;
            int v = isConnected.size();
            vector<int> adj[v];
            for(int i =0;i<v;i++){
                for(int j =0;j<v;j++){
                    if(isConnected[i][j] == 1 && i!=j){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            int vis[v];
            memset( vis, 0, v*sizeof(int) );
                        
            for(int i = 0; i<v;i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i,adj,vis);
                    
                }
            }
            return cnt;

    }
};