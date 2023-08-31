class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > totalSum) {
        return 0;
    }

    int n = nums.size();
    vector<int> dp(2 * totalSum + 1, 0);
    dp[totalSum] = 1; // Base case

    for (int num : nums) {
        vector<int> nextDp(2 * totalSum + 1, 0);
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] > 0) {
                nextDp[i + num] += dp[i];
                nextDp[i - num] += dp[i];
            }
        }
        dp = nextDp;
    }

    return dp[totalSum + target];
}
};