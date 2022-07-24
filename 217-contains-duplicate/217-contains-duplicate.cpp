class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int size=nums.size();

        unordered_map<int, int> contains;
        
        for(int i=0;i<size;i++)
        {
            contains[nums[i]]+=1;
            if(contains[nums[i]]>1)
            {
                return true;
            }
                
        }

        return false;
    }
};