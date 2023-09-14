class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize){
            return false;
        }
        map<int,int> mp;
        for(int i : hand){
            mp[i]++;
        }
        sort(hand.begin(), hand.end());
        for (int i = 0; i < hand.size(); i++) {
            if (mp[hand[i]] == 0) {
                continue;
            }
            
            for (int j = 0; j < groupSize; j++) {
                int currCard = hand[i] + j;
                
                if (mp[currCard] == 0) {
                    return false;
                }
                
                mp[currCard]--;
            }
        }
        
        return true;
    }
};