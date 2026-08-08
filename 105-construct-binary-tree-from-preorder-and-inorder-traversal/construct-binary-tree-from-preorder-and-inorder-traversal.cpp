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
    int n;
    TreeNode* construct(int& i,int l,int r,vector<int>&preorder,vector<int>&inorder){
        if(i>=n or l>r) return nullptr;
        int mid;
        for(int j=l;j<=r;j++){
            if(preorder[i]==inorder[j]){
                mid=j;
                break;
            }
        }  
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=construct(i,l,mid-1,preorder,inorder);
        root->right=construct(i,mid+1,r,preorder,inorder);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=preorder.size();
        int idx=0;
        return construct(idx,0,n-1,preorder,inorder);
    }
};