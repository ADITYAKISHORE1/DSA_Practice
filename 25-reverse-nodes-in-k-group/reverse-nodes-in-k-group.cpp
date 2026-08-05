class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* root=new ListNode(0,head);
        ListNode* ptr=head;
        int grp=0;
        while(ptr!=nullptr){
            grp++;
            ptr=ptr->next;
        }
        grp/=k;
        ListNode* prev=root,*cur=head;
        while(prev!=nullptr){
            for(int i=0;i<k-1;i++){
                ListNode* tmp=cur->next;
                cur->next=tmp->next;
                tmp->next=prev->next;
                prev->next=tmp;
            }
            if(--grp==0) break;
            prev=cur;
            cur=cur->next;
        }
        return root->next;
    }
};