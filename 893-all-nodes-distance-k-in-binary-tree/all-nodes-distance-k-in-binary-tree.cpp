/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*,TreeNode*> mpp;
    void f(TreeNode* ptr,TreeNode* par){
        if(ptr==nullptr) return;
        mpp[ptr]=par;
        f(ptr->left,ptr);
        f(ptr->right,ptr);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* ptr=root;
        f(ptr,nullptr);
        unordered_map<TreeNode*,bool> vis;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        vis[target]=true;
        vector<int> v;
        while(!q.empty()){
            auto [pt,dist]=q.front();
            q.pop();
            if(dist==k){
                v.push_back(pt->val);
                continue;
            }
            if(pt->left!=nullptr and vis[pt->left]==0){
                q.push({pt->left,dist+1});
                vis[pt->left]=1;
            }
            if(pt->right!=nullptr and vis[pt->right]==0){
                q.push({pt->right,dist+1});
                vis[pt->right]=1;
            }
            if(mpp[pt]!=nullptr and vis[mpp[pt]]==0){
                q.push({mpp[pt],dist+1});
                vis[mpp[pt]]=1;
            }
        }
        return v;
    }
};