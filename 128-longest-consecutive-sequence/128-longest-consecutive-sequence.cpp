class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int result=0;
        unordered_set<int> :: iterator itr;
        for(itr = s.begin();itr!=s.end();itr++){
            int curr = *itr;
            if(s.find(curr-1)!=s.end()){
                continue;
            }
            int length=1;
            while(s.find(curr+1)!=s.end()){
                length++;
                curr++;
            }
            result = max(length,result);
        }
        return result;
        
    }
};