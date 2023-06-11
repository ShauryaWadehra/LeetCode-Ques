class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> dist(r,vector<int>(c,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<r;i++){
            for(int j = 0; j<c;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[row][col] = step;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i = 0;i<4;i++){
                int nrow = row+dx[i];
                int ncol= col+dy[i];
                if(nrow>=0&&nrow<r&&ncol>=0&&ncol<c&&mat[nrow][ncol]==1){
                    mat[nrow][ncol] = 0;
                    q.push({{nrow,ncol},step+1});
                }                
            }
        }
        return dist;
    }
};