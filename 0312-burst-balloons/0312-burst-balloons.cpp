class Solution {
public:
    int dfs(vector<int>& nums,vector<vector<int>> &dp,int l, int r){
        if(l>r){
            return 0;
        }
        if(dp[l][r]!=0){
            return dp[l][r];
        }
        int coins = 0;
        for(int i = l;i<=r;i++){
            coins = nums[l-1]*nums[i]*nums[r+1] + dfs(nums,dp,l,i-1) + dfs(nums,dp,i+1,r);
            dp[l][r] = max(dp[l][r],coins);
        }
        return dp[l][r];
     
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        return dfs(nums,dp,1,n-2);
    }
};