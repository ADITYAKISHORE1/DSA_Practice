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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1001, head);
        ListNode* prev = dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->val == cur->next->val) {
                int x = cur->val;
                while (cur != nullptr && cur->val == x)
                    cur = cur->next;

                prev->next = cur; 
            } else {
                prev = cur; 
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};