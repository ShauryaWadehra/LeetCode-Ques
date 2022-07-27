class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        int mid = (low+high)/2;
        while(low<=high){
            int mid = (low+high)/2;
            if(target>nums[mid]){
                low = mid+1;
            }
            else if(target<nums[mid]){
                high = mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};