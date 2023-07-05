class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] == 1 or grid[n-1][m-1] == 1)return -1;
        pair<int,int>source={0,0};
        pair<int,int>destination={n-1,m-1};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        q.push({1,source});
        dis[source.first][source.second]=0;
        int delrow[8]={-1,-1,-1,1,1,1,0,0};
        int delcol[8]={0,1,-1,0,-1,1,-1,1};
        while(!q.empty()){
            auto it=q.front();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==destination.first and col==destination.second){
                ans=dist;
                break;
            }
            q.pop();
            for(int i=0;i<8;i++){
                int r=row+delrow[i];
                int c=col+delcol[i];
                if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==0&&dis[r][c]>dist+1){
                    dis[r][c]=dist+1;
                    q.push({dis[r][c],{r,c}});
                }
            }
        }
        if(dis[destination.first][destination.second]==INT_MAX)return -1;
        return ans;
    }
};