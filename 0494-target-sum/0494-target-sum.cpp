class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum)
        {
            return 0;
        }

        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);

        dp[0][0] = 1; // Base case

        for (int i = 1; i <= n; ++i)
        {
            int num = nums[i - 1];
            for (const auto &entry : dp[i - 1])
            {
                int sum = entry.first;
                dp[i][sum + num] += entry.second;
                dp[i][sum - num] += entry.second;
            }
        }

        return dp[n][target];
    }
};