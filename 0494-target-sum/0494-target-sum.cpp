class Solution {
public:
    int f(vector<int>& nums, int target,int index,int total, map<pair<int, int>, int> &dp){
        if (index == nums.size()) {
            return total == target ? 1 : 0;
        }
        if (dp.find({index, total}) != dp.end()) {
            return dp[{index, total}];
        }
        dp[{index, total}] = f(nums,target,index+1,total+nums[index],dp) + f(nums,target,index+1,total-nums[index],dp);
        return dp[{index, total}]; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return f(nums,target,0,0,dp);
    }
};