class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Three variables to store maxiumum three numbers till now.
        long long firstMax = numeric_limits<long long>::min();
        long long secondMax = numeric_limits<long long>::min();
        long long thirdMax = numeric_limits<long long>::min();
        
        for (int& num : nums) {
            // This number is already used once, thus we skip it.
            if (firstMax == num || secondMax == num || thirdMax == num) {
                continue;
            }
            
            // If current number is greater than first maximum,
            // It means that this is the greatest number and first maximum and second max
            // will become the next two greater numbers.
            if (firstMax <= num) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            // When current number is greater than second maximum,
            // it means that this is the second greatest number.
            else if (secondMax <= num) {
                thirdMax = secondMax;
                secondMax = num;
            }
            // It is the third greatest number.
            else if (thirdMax <= num) {
                thirdMax = num;
            }
        }
        
        // If third max was never updated, it means we don't have 3 distinct numbers.
        if (thirdMax == numeric_limits<long long>::min()) {
            return firstMax;
        }
        
        return thirdMax;
    }
};