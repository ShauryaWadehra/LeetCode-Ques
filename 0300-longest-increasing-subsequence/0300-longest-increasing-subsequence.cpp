class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int res = 1;
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};