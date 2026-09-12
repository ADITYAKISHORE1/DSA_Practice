/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void dfs(Node* root,Node* nxt){
        if(root==nullptr) return;
        root->next=nxt;
        dfs(root->left,root->right);
        if(nxt!=nullptr){
            dfs(root->right,nxt->left);
            dfs(nxt->left,nxt->right);
        }
    }
public:
    Node* connect(Node* root) {
        dfs(root,nullptr);
        return root;
    }
};