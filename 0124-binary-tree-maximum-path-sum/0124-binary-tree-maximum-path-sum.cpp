/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root,int &res){
        if(root == NULL){
            return 0;
        }
       
        int leftmax = max(f(root->left,res),0);
        int rightmax = max(f(root->right,res),0);
         
        res = max(res, root->val + leftmax + rightmax);
        return root->val + max(leftmax,rightmax);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        f(root,res);
        return res;         
    }
};