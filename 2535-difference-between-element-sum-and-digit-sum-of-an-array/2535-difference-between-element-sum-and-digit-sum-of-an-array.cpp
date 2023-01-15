class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int sum2 = 0;
        for(int i =0;i<nums.size();i++){
            sum2+=nums[i];
            while(nums[i]>0){
                int g = nums[i]%10;
                sum+=g;
                nums[i] = nums[i]/10;
            }
        }
        return abs(sum2-sum);
    }
};