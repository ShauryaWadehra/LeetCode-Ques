class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(k==1){
            return 0;
        }
        int i = 0;
        int j = k-1;
        int minn = 1e5;
        while(j<nums.size()){
            minn = min(minn,nums[j]-nums[i]);
            i++;
            j++;
        }
        return minn;
    }
};