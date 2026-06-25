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
public:
    bool isCompleteTree(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        if (root != nullptr) {
            v.push_back(root->val);
            q.push(root);
        }
        while (!q.empty()) {
            int sz = q.size();
            if (sz--) {
                auto r = q.front();
                q.pop();
                if (r->left != nullptr) {
                    v.push_back(r->left->val);
                    q.push(r->left);
                } else
                    v.push_back(-1);
                if (r->right != nullptr) {
                    v.push_back(r->right->val);
                    q.push(r->right);
                } else
                    v.push_back(-1);
            }
        }
        for(int i=1;i<v.size()-1;i++){
            if(v[i]==-1 and v[i+1]>-1) return false; 
        }
        return true;
    }
};