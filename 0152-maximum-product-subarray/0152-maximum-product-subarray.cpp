class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int cmin = 1,cmax = 1;
        for(int i = 0;i<nums.size();i++){
            int n = nums[i];
            int tmp = cmax*n;
            int tmp2 = cmin*n;
            cmax = max(max(tmp,tmp2),n);
            cmin = min(min(tmp,tmp2),n);
            res = max(cmax,res);
        }
        return res;
    }
};