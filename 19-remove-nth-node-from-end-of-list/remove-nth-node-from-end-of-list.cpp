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
        ListNode* slowp=head;
        ListNode* fastp=head;
        for(int i=0;i<n;i++){
            fastp=fastp->next;
        }
        if(fastp==nullptr) return head->next;
        while(fastp->next!=nullptr){
            slowp=slowp->next;
            fastp=fastp->next;
        }
        fastp=slowp->next;
        slowp->next=fastp->next;
        delete fastp;
        return head;
    }
};