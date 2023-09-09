class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if(digits.empty()){
            return {};
        }
        string curr = "";
        vector<string> res;
        dfs(digits,curr,0,m,res);
        return res;
    }
    void dfs(string digits,string &curr, int index, unordered_map<char,string>&m,vector<string> &res){
        if(index == digits.size()){
            res.push_back(curr);
            return;
        }
        string str = m[digits[index]];
        for(int i = 0;i<str.size();i++){
            curr.push_back(str[i]);
            dfs(digits,curr,index+1,m,res);
            curr.pop_back();
        }
    }
};