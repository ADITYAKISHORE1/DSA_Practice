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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* root=head;
        while(root->next!=nullptr){
            int v1=root->val;
            int v2=root->next->val;
            ListNode* ptr=new ListNode(gcd(v1,v2));
            ptr->next=root->next;
            root->next=ptr;
            root=root->next->next;
        }
        return head;
    }
};