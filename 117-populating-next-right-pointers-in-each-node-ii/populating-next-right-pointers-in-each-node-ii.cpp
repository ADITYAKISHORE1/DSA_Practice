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
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                Node* p = q.front();
                q.pop();
                Node* nxt = nullptr;
                if (!q.empty() and n > 0)
                    nxt = q.front();
                p->next = nxt;
                if (p->left != nullptr)
                    q.push(p->left);
                if (p->right != nullptr)
                    q.push(p->right);
            }
        }
        return root;
    }
};