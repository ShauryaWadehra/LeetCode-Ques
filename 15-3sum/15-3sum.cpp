class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n-2;i++){
            if(nums[i]>0){
                break;
            }
            if(i>0 &&nums[i] == nums[i-1]){
                continue;
            }
            int ptr1 = i+1;
            int ptr2 = n-1;
            while(ptr1<ptr2){
                int sum = nums[i] + nums[ptr1] + nums[ptr2];
                if(sum>0){
                    ptr2--;
                }else if(sum<0){
                    ptr1++;
                }else{
                    result.push_back({nums[i], nums[ptr1], nums[ptr2]});
                    ptr1++;
                    while(nums[ptr1] == nums[ptr1-1] && ptr1<ptr2){
                        ptr1++;
                    }
                }
            }
        }
        return result;
        
        
    }
};