class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowrow = 0;
        int highrow = matrix.size()-1;
        while(lowrow<highrow){
            int midrow = (lowrow + highrow) /2;
            if(matrix[midrow][0] == target){
                return true;                
            }
            if (matrix[midrow][0] < target && target < matrix[midrow + 1][0]) {
                lowrow = midrow;
                break;
            }
            if(target<matrix[midrow][0]){
                highrow = midrow - 1;
            }
            else {
                lowrow = midrow +1;
            }
        }
        int low = 0,high = matrix[0].size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[lowrow][mid]==target){
                return true;
            }
            if(matrix[lowrow][mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};