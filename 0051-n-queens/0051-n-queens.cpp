class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> diag1;  
    unordered_set<int> diag2; 
    
    void f(int n,int row,vector<vector<string>> &res,vector<string> &board){
        if(row == n){
            res.push_back(board);
            return;
        }
        for(int i = 0;i<n;i++){
            if(cols.find(i)!=cols.end()||diag1.find(row-i)!=diag1.end()||diag2.find(row+i)!=diag2.end()){
                continue;
            }
            cols.insert(i);
            diag1.insert(row-i);
            diag2.insert(row+i);
            board[row][i] = 'Q';
            f(n,row+1,res,board);
            cols.erase(i);
            diag1.erase(row - i);
            diag2.erase(row + i);
            board[row][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        f(n,0,res,board);
        return res;
    }
};