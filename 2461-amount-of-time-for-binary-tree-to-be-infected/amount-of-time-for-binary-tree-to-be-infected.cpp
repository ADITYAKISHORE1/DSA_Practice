class Solution {
        unordered_map<int,vector<int>> adj;
    void dfs(TreeNode* root){
        if(root->left!=nullptr){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right!=nullptr){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(root!=nullptr) dfs(root);
        queue<pair<int,int>> q;
        q.push({start,0});
        unordered_map<int,int> vis;
        vis[start]=1;
        int ans=0;
        while(!q.empty()){
            auto [v,c]=q.front();
            q.pop();
            ans=max(ans,c);
            for(auto& adjNode:adj[v]){
                if(vis[adjNode]==0){
                    vis[adjNode]=1;
                    q.push({adjNode,c+1});
                }
            }
        }
        return ans;
    }
};