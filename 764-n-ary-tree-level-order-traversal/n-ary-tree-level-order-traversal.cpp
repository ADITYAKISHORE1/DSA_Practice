/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root!=nullptr) q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while (sz--) {
                auto r = q.front();
                q.pop();
                v.push_back(r->val);
                for (auto& ch : r->children) {
                    if (ch != nullptr) {
                        q.push(ch);
                    }
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};