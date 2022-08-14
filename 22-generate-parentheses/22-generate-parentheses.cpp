class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0,0,"",res,n);
        return res;
    }
    void generate(int open,int closed,string str, vector<string> &result, int n){
            if(open == n && closed == n){
                result.push_back(str);
                return;
            }
            if( open<n){
                generate(open + 1 ,closed,str+'(',result,n);
            }
            if(open>closed){
                generate(open ,closed + 1,str+ ')', result,n);
            }
       
    }
};