class Solution {
public:
    int climbStairs(int n) {
        if(n<=0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        
        int prev = 2;
        int prev2 = 1;
        int ans = 0;
        for(int i = 2;i<n;i++){
            ans = prev+prev2;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};