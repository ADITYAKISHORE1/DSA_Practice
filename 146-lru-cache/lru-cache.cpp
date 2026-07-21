class DLL {
public:
    int key;
    int val;
    DLL* prev;
    DLL* next;
    DLL(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
    unordered_map<int,DLL*> mpp;
    DLL* head;
    DLL* tail;
    int capacity;

    void deleteNode(DLL* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insertNode(DLL* node){
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
    }
public:
    LRUCache(int capacity) {
        head=new DLL(-1,-1);
        tail=new DLL(-1,-1);
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        DLL* node=mpp[key];
        deleteNode(node);
        insertNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if(mpp.find(key)==mpp.end()){
            DLL*  node=new DLL(key,value);
            mpp[key]=node;
            insertNode(node);
        }else{
            DLL* node=mpp[key];
            deleteNode(node);
            node->val=value;
            insertNode(node);
        }
        if(mpp.size()>capacity){
            DLL* node=tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
            delete node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */