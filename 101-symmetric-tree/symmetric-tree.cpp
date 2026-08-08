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
    bool chkPali(vector<int>&v){
        int l=0,r=v.size()-1;
        while(l<=r){
            if(v[l]!=v[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp=new TreeNode(-101);
        while(!q.empty()){
            int sz=q.size();
            vector<int> arr;
            while(sz--){
                TreeNode* node=q.front();
                q.pop();
                int v=node->val;
                arr.push_back(v);
                if(v==-101 and node->left==nullptr and node->right==nullptr) continue;
                if(node->left!=nullptr){
                    q.push(node->left);
                }else q.push(temp);
                if(node->right!=nullptr){
                    q.push(node->right);
                }else q.push(temp);
            }
            if(!chkPali(arr)){
                return false;
            }
        }
        return true;
    }
};