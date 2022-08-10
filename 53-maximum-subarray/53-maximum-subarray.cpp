class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = nums[0];
        int curr =0;
        for(int i :nums){
            curr = max(i, curr+ i);
            maxs = max(maxs,curr);
        }
        return maxs;
    }
};