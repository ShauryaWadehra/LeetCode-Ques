class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = nums[0];
        int curr =0;
        for(int i :nums){
            if(curr<0){
                curr =0;
            }
            curr += i;
            maxs = max(maxs,curr);
        }
        return maxs;
    }
};