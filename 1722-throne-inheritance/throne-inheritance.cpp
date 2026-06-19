class Node {
public:
    string val;
    bool isDead;
    vector<Node*> child;
    Node(string s) : val(s) { isDead = false; }
};
class ThroneInheritance {
    Node* root;
    unordered_map<string,Node*> dir;

    void printDFS(Node* node, vector<string>& v) {
        if (!node->isDead)
            v.push_back(node->val);
        for (auto& c : node->child) {
            printDFS(c, v);
        }
    }

public:
    ThroneInheritance(string kingName) { 
        root = new Node(kingName); 
        dir[kingName]=root;
    }

    void birth(string parentName, string childName) {
        Node* ch = new Node(childName);
        dir[childName]=ch;
        dir[parentName]->child.push_back(ch);
    }

    void death(string name) { 
        dir[name]->isDead = true; 
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        Node* ptr = root;
        printDFS(ptr, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */