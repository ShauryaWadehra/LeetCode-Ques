class Solution {
public:
     
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int l = n-2;l>=1;l--){
            for(int r = 1;r<=n-2;r++){
                if(l>r)continue;
                int coins = 0;
                for(int i = l;i<=r;i++){
                    coins = nums[l-1]*nums[i]*nums[r+1] + dp[l][i-1] +  dp[i+1][r];
                    dp[l][r] = max(dp[l][r],coins);
                }
            }
        }
        return  dp[1][n-2];
    }
};