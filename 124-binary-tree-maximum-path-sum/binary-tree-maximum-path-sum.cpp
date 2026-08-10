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
    int maxsum=INT_MIN;
    int f(TreeNode* root){
        if(root==nullptr) return -1e9;
        int l=f(root->left);
        int r=f(root->right);
        int t=root->val+max(0,l)+max(0,r);
        maxsum=max(maxsum,t);
        return root->val+max(0,max(l,r));
    }
public:
    int maxPathSum(TreeNode* root) {
        f(root);
        return maxsum;
    }
};