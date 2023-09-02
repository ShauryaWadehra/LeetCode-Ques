class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int srt = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[srt] = nums[i];
                srt++;
            }
        }
        return srt;
    }
};