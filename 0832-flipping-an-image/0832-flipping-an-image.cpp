class Solution {
public:
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
if(A.empty()){
return A;
}
for(auto& row : A){
std::reverse(std::begin(row), std::end(row));
std::for_each(row.begin(), row.end(), [](int& item){ item = 1 - item; });
}
return A;
}
};