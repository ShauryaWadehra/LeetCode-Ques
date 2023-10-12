class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size();i++){
            if(nums[i]%2 == 0){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
        }
        int preSum = 0;
        int cnt = 0;
        map<int,int> mp;
        mp[0] = 1;
        for(int i = 0;i<nums.size();i++){
            preSum += nums[i];
            int r = preSum - k;
            cnt += mp[r];
            mp[preSum] += 1;
        }
        return cnt;
    }
};