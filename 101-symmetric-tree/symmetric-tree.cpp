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
    bool f(TreeNode* l,TreeNode* r){
        if(l==nullptr and r==nullptr) return true;
        if(l==nullptr or r==nullptr) return false;
        if(l->val==r->val){
            return (f(l->right,r->left)&f(l->left,r->right));
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return f(root->left,root->right);
    }
};