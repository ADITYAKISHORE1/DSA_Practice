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
    int cnt = 0;
    void dfs(TreeNode* root, int hash) {
        if (root == nullptr) {
            return;
        }
        hash ^= (1 << root->val);
        if (root->left == nullptr and root->right == nullptr) {
            cnt += ((hash & (hash - 1)) == 0);
            return;
        }
        dfs(root->left, hash);
        dfs(root->right, hash);
    }

public:
    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root, 0);
        return cnt;
    }
};