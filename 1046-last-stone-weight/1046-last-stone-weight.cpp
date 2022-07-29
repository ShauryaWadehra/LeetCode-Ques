class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mxhp;
        for(int i=0;i<stones.size();i++){
            mxhp.push(stones[i]);            
        }
        while(mxhp.size()>1){
            int f = mxhp.top();
            mxhp.pop();
            int s = mxhp.top();
            mxhp.pop();
            if(f>s){
                mxhp.push(f-s);
            }
        }
        if(mxhp.empty()){
            return 0;
        }
        return mxhp.top();
      
    }
};