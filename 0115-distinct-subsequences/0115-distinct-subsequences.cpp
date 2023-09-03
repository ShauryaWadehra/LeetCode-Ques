class Solution {
public:
    
    int numDistinct(string s, string t) {
        unsigned long long n = s.size();
        unsigned long long m = t.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i = 0;i<=n;i++){
            dp[i][m] = 1;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(s[i] == t[j]){
                    dp[i][j] =  dp[i+1][j+1] + dp[i+1][j];
                }else{
                    dp[i][j] =  dp[i+1][j];
                }
            }
        }
        if(dp[0][0]> INT_MAX) return -1;
        return dp[0][0];
    }
};