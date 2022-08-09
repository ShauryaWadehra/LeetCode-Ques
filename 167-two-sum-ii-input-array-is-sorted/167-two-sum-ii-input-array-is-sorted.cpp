class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        int ptr1 =0; int ptr2 =n-1;
        while(ptr1<ptr2){
            int sum = numbers[ptr1] + numbers[ptr2];
            if(sum > target){
                ptr2--;
            }else if(sum<target){
                ptr1++;
            }else{
                ans.push_back(ptr1+1);
                ans.push_back(ptr2+1);
                break;
            }
        }
        
        return ans;
    }
};