class MyCircularDeque {
    struct Node {
        int val;
        Node* next;
        Node* prev;
    };
    int k;
    int size;
    Node* front;
    Node* back;

public:
    MyCircularDeque(int k) {
        front = nullptr;
        back = nullptr;
        size = 0;
        this->k = k;
    }

    bool insertFront(int value) {
        if (size == k)
            return false;
        Node* ptr = new Node();
        ptr->val = value;
        if (size == 0) {
            ptr->next = nullptr;
            ptr->prev = nullptr;
            front = ptr;
            back = ptr;
        } else {
            ptr->next = front;
            ptr->prev = nullptr;
            front->prev = ptr;
            front = front->prev;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (size == k)
            return false;
        Node* ptr = new Node();
        ptr->val = value;
        if (size == 0) {
            ptr->next = nullptr;
            ptr->prev = nullptr;
            front = ptr;
            back = ptr;

        } else {
            ptr->next = nullptr;
            ptr->prev = back;
            back->next = ptr;
            back = back->next;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0)
            return false;
        Node* ptr = front;
        if (size == 1) {
            delete front;
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
            delete ptr;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0)
            return false;
        Node* ptr = back;
        if (size == 1) {
            delete back;
            front = back = nullptr;
        } else {
            back = back->prev;
            back->next = nullptr;
            delete ptr;
        }
        size--;
        return true;
    }

    int getFront() {
        if (size == 0)
            return -1;
        return front->val;
    }

    int getRear() {
        if (size == 0)
            return -1;
        return back->val;
    }

    bool isEmpty() { return (size == 0); }

    bool isFull() { return (size == k); }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */