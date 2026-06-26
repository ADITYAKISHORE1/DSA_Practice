class Solution {
    int dfs(TreeNode* root,int& cnt){
        if(root==nullptr) return 0;
        int l=dfs(root->left,cnt);
        int r=dfs(root->right,cnt);
        cnt+=abs(l)+abs(r);
        return root->val+l+r-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int cnt=0;
        dfs(root,cnt);
        return cnt;
    }
};