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
    int maxm = 0;
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        return max(l,r)+1;
    }
    pair<bool, int> dfs(TreeNode* root, int start) {
        if (root == nullptr)
            return {false, 0};
        if (root->val == start) {
            maxm=max(maxm,dfs(root));
            return {true, 1};
        }
        pair<bool, int> l = dfs(root->left, start);
        pair<bool, int> r = dfs(root->right, start);
        if (l.first or r.first) {
            maxm = max(maxm, l.second + r.second + 1);
        }
        if (l.first)
            return make_pair(true, l.second + 1);
        else if (r.first)
            return make_pair(true, r.second + 1);
        return make_pair(false, max(l.second, r.second) + 1);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        pair<bool, int> p = dfs(root, start);
        maxm = max(maxm, p.second);
        return maxm - 1;
    }
};