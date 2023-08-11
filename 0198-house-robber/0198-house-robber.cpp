class Solution {
public:
    int rob(vector<int>& nums) {
        int temp,r1=0,r2=0;
        for(auto i : nums){
            temp = max(i + r1,r2);
            r1 = r2;
            r2 = temp;
        }
        return temp;
    }
};