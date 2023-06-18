class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = 1e9;
        for(int i = 1;i<nums.size();i++){
            m = min(m,nums[i]-nums[i-1]);
        }
        return m;
    }
};