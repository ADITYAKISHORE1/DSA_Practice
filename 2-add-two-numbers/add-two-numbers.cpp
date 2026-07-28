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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* root=new ListNode();
        ListNode* t=root;
        while(l1!=nullptr and l2!=nullptr){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode* ptr=new ListNode(sum%10);
            t->next=ptr;
            t=t->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            int sum=l1->val+carry;
            carry=sum/10;
            ListNode* ptr=new ListNode(sum%10);
            t->next=ptr;
            t=t->next;
            l1=l1->next;
        }
        while(l2!=nullptr){
            int sum=l2->val+carry;
            carry=sum/10;
            ListNode* ptr=new ListNode(sum%10);
            t->next=ptr;
            t=t->next;
            l2=l2->next;
        }
        while(carry>0){
            ListNode* ptr=new ListNode(carry%10);
            carry/=10;
            t->next=ptr;
            t=t->next;
        }
        return root->next;
    }
};