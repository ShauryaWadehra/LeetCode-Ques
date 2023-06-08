class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& image, int nc, int ic){
        int n = image.size();
        int m = image[0].size();
        image[r][c] = nc;
        for(int drow = -1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){
                    if((drow==-1&&dcol==-1) || (drow==-1&&dcol==1) || (drow==1&&dcol==-1) || (drow==1&&dcol==1)){
                        continue;
                    }
                    int nrow = r+drow;
                    int ncol = c+dcol;
                    if(nrow<n && nrow >=0 && ncol<m && ncol >=0 && image[nrow][ncol] == ic && image[nrow][ncol] != nc){
                        dfs(nrow,ncol,image,nc,ic);
                    }                 
                }
            }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        dfs(sr,sc,image,color,ic);
        return image;
    }
};
