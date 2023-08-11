class Solution {
public:
    int f(string s, int l, int r){
        int res =0;
        while(l>=0 && r<s.length() && s[l] == s[r]){
                res++;
                l--;
                r++;
        }
        return res;
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0;i<s.length();i++){
            res += f(s,i,i);
            res += f(s,i,i+1);
        }
        return res;
    }
};