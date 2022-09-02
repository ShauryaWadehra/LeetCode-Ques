class Solution {
public:
    int bins(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low + high)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
            }
        }
        return -1;
    }
    int bin(vector<int>& nums, int low, int high, int target){
        while(low<=high){
            int mid = (low + high)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target)return 0;
            else return -1;
        }
        for(int i =1;i<nums.size();i++){
            if(nums[i]>=nums[i-1]){
                if(i == nums.size()-1){
                    return bins(nums,target);
                }
                continue;
            }else{
                return max(bin(nums,0,i-1,target),bin(nums,i,nums.size()-1,target));
            }
        }
        return -1;
    }
};