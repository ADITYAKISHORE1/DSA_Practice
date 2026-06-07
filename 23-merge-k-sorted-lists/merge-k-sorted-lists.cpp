class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* node : lists)
            if (node != nullptr)
                pq.push(node);

        ListNode* root = nullptr;
        ListNode* ptr = nullptr;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            if (root == nullptr) {
                ptr = node;
                root = node;
            } else {
                ptr->next = node;
                ptr = ptr->next;
            }
            if (node->next != nullptr)
                pq.push(node->next);
        }
        
        return root;
    }
};