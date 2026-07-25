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
    TreeNode* f(int&  idx,int start,int end,vector<int>&postorder,vector<int>& inorder){
        if(start>end) return nullptr;
        int i=start;
        for(;i<=end;i++){
            if(postorder[idx]==inorder[i]){
                break;
            }
        }
        TreeNode* root=new TreeNode(postorder[idx]);
        idx--;
        root->right=f(idx,i+1,end,postorder,inorder);
        root->left=f(idx,start,i-1,postorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int idx=n-1;
        return f(idx,0,n-1,postorder,inorder);
    }
};