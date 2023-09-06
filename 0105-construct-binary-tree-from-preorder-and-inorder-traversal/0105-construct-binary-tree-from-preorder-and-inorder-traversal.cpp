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
    TreeNode* build(vector<int>& p, vector<int>& inorder,int &index,int l,int r){
        if(l>r){
            return NULL;
        }
        TreeNode* root = new TreeNode(p[index]);
        int split = 0;
        for(int i = 0;i<inorder.size();i++){
            if(p[index] == inorder[i]){
                split = i;
                break;
            }
        }
        index++;
        root->left = build(p,inorder,index,l,split-1);
        root->right = build(p,inorder,index,split+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        int index = 0;
        return build(p,i,index,0,i.size()-1);
    }
};