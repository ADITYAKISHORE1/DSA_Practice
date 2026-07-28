class MLL{
public:
    int val;
    int mn;
    MLL* next;
    MLL* prev;
    MLL(){
        val=0;
        mn=INT_MAX;
        next==nullptr;
        prev==nullptr;
    }
};
class MinStack {
    MLL* root;
    MLL* t;
public:
    MinStack() {
        root=new MLL();
        t=root;
    }
    
    void push(int value) {
        MLL* ptr=new MLL();
        ptr->val=value;
        ptr->mn=min(value,t->mn);
        ptr->prev=t;
        t->next=ptr;
        t=ptr;
    }
    
    void pop() {
        MLL* ptr=t;
        t=t->prev;
        t->next=nullptr;
        delete ptr;
    }
    
    int top() {
        return t->val;
    }
    
    int getMin() {
        return t->mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */