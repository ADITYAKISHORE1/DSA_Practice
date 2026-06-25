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
    unordered_map<long long,long long> hash;
    long long dfs(TreeNode* root){
        if(root==nullptr) return 0;
        long long sum=root->val;
        long long l=dfs(root->left);
        long long r=dfs(root->right);
        sum+=l+r;
        hash[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        dfs(root);
        long long maxFreq=0;
        for(auto& i:hash){
            maxFreq=max(maxFreq,i.second);
        }
        for(auto& i:hash){
            if(i.second==maxFreq) ans.push_back(i.first);
        }
        return ans;
    }
};