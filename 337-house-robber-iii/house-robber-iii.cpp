/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, int> dp;

public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (dp.contains(root))
            return dp[root];
        int take = root->val;
        if (root->left != nullptr)
            take += rob(root->left->left) + rob(root->left->right);
        if (root->right != nullptr)
            take += rob(root->right->left) + rob(root->right->right);

        int notTake = rob(root->left) + rob(root->right);
        return dp[root] = max(take, notTake);
    }
};