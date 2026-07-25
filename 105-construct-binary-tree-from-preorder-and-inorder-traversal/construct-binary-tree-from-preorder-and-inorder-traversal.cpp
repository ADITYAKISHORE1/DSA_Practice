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
    TreeNode* f(int & idx,int start,int end,vector<int>&preorder,vector<int>& inorder){
        if(start>end) return nullptr;
        int i=start;
        for(;i<=end;i++){
            if(preorder[idx]==inorder[i]){
                break;
            }
        }
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        root->left=f(idx,start,i-1,preorder,inorder);
        root->right=f(idx,i+1,end,preorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
        return f(idx,0,n-1,preorder,inorder);
    }
};