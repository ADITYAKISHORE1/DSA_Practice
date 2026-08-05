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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* ptr=head;
        while(ptr!=nullptr){
            sz++;
            ptr=ptr->next;
        }
        if(sz==n and sz==1) return nullptr; 
        sz=sz-n;
        if(sz==0) return head->next;
        ListNode* prev;
        ptr=head;
        while(sz-- and ptr!=nullptr){
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=ptr->next;
        return head;
    }
};