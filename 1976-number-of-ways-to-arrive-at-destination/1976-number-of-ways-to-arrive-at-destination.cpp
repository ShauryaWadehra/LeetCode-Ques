#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<ll,ll>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,LONG_MAX),ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (ll)(1e9+7);
        pq.push({0,0});        
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                ll adjnode = it.first;
                ll wt = it.second;
                if(dist[adjnode]>dis+wt){
                    dist[adjnode] = dis+wt;
                    pq.push({dis+wt,adjnode});
                    ways[adjnode] = ways[node];
                } 
                else if(dist[adjnode] == dis+wt){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
    
};