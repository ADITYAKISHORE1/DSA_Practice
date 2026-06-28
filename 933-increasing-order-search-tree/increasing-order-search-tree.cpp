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
    TreeNode* a;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        TreeNode* tmp=new TreeNode(root->val);
        a->right=tmp;
        a=a->right;
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* r=new TreeNode();
        a=r;
        inorder(root);
        return r->right;
    }
};