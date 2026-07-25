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
    unordered_map<int,int> mpp;
    TreeNode* f(int&  idx,int start,int end,vector<int>&postorder,vector<int>& inorder){
        if(start>end) return nullptr;
        int i=mpp[postorder[idx]];
        TreeNode* root=new TreeNode(postorder[idx]);
        idx--;
        root->right=f(idx,i+1,end,postorder,inorder);
        root->left=f(idx,start,i-1,postorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        for(int i=0;i<n;i++) mpp[inorder[i]]=i;
        int idx=n-1;
        return f(idx,0,n-1,postorder,inorder);
    }
};