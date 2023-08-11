class Solution {
public:
    int rob1(vector<int>& nums){
        int r1=0,r2=0,temp;
        for(auto i : nums){
            temp = max(r1+i,r2);
            r1=r2;
            r2 = temp;
        }
        return temp;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> v1,v2;
        for(int i = 1;i<nums.size();i++){
            v1.push_back(nums[i]);
        }
        for(int i  = 0;i<nums.size()-1;i++){
            v2.push_back(nums[i]);
        }
        return max(rob1(v1),rob1(v2));
    }
};