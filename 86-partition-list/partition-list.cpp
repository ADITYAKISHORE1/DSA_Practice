/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* r=head;
        ListNode* end;
        int sz=0;
        while(r!=nullptr){
            sz++;
            r=r->next;
            if(r!=nullptr and r->next==nullptr) end=r;
        }
        if(sz==1) return head;
        ListNode* root=new ListNode(0,head);
        r=root;
        for(int i=0;i<sz;i++){
            if(r->next!=nullptr and r->next->val>=x){
                end->next=r->next;
                r->next=r->next->next;
                end=end->next;
                end->next=nullptr;
            }
            else r=r->next;
        }
        return root->next;
    }
};
// 6    1 2 3 4