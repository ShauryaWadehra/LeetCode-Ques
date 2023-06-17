class Solution {

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j = 0 ; j<m;j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }        
        for(int i = 0;i<n;i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        int del[] = {-1,0,1,0,-1}; 
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int nrow = r + del[i];
                int ncol = c + del[i+1];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};