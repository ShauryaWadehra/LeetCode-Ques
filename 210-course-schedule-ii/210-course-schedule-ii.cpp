class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        int inDeg[numCourses];
        memset( inDeg, 0, numCourses*sizeof(int) );

        for(int i = 0;i<numCourses;i++){
            for(auto it : adj[i]){
                inDeg[it]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(!inDeg[i]){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for(auto i : adj[n]){
                inDeg[i]--;
                if(!inDeg[i]){
                    q.push(i);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};