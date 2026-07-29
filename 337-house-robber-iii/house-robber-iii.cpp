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
    unordered_map<TreeNode*,unordered_map<bool,int>> dp;
    int f(TreeNode* root,bool t){
        if(root==nullptr) return 0;
        if(dp.contains(root) and dp[root].contains(t)) return dp[root][t];
        int take=0;
        if(t){
            take=root->val+f(root->left,false)+f(root->right,false);
        }
        int notTake=f(root->left,true)+f(root->right,true);
        return dp[root][t]=max(take,notTake);
    }
public:
    int rob(TreeNode* root) {
        return f(root,true);
    }
};