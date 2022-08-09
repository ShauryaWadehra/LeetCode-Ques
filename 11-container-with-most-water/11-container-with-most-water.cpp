class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,r = height.size()-1,res = 0;
        while(l<r){
            int area = (r-l)*(min(height[l],height[r]));
            res = max(res,area);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return res;

    }
};