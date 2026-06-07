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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<TreeNode*,int> child;
        for (auto& i : descriptions) {
            TreeNode* p;
            TreeNode* c;
            if (!nodes.contains(i[0])) {
                p = new TreeNode(i[0]);
                nodes[i[0]] = p;
            }
            else p=nodes[i[0]];
            if (!nodes.contains(i[1])) {
                c = new TreeNode(i[1]);
                nodes[i[1]] = c;
            }else c=nodes[i[1]];
            if (i[2]) {
                p->left = c;
            } else {
                p->right = c;
            }
            child[c]=1;
        }
        for (auto& i : nodes) {
            if(child[i.second]==0) return i.second;
        }
        return nullptr;
    }
};