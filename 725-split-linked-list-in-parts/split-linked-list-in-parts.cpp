class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            len++;
            ptr = ptr->next;
        }
        ptr = head;
        vector<ListNode*> ans;
        while (ptr != nullptr) {
            int n = (len + k - 1) / k;
            k--;
            len-=n;
            ans.push_back(ptr);
            while(--n){
                ptr=ptr->next;
            }
            ListNode* tmp=ptr->next;
            ptr->next=nullptr;
            ptr=tmp;
        }
        while(k--) ans.push_back(nullptr);
        return ans;
    }
};