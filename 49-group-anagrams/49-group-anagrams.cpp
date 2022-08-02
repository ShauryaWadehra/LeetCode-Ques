class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string temp = strs[i];
            vector<int> count(26,0);
            for(int j=0;j<strs[i].size();j++){
                count[strs[i][j]-'a']++;
            }
            string str;
            for(int i: count){
                str.push_back(i+'0');
            }
            mp[str].push_back(temp);
        }
        
        vector<vector<string>> result;
        for(auto itr = mp.begin();itr!=mp.end();++itr){
            result.push_back(itr->second);
        }
        return result;
    }
   
};