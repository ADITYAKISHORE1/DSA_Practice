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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ptr = dummy;
        while (dummy != nullptr) {
            ListNode *cur, *nxt;
            cur = ptr->next;
            if (cur != nullptr)
                nxt = cur->next;
            if (cur == nullptr or nxt == nullptr)
                break;
            ptr->next = nxt;
            cur->next = nxt->next;
            nxt->next = cur;
            ptr = cur;
        }
        return dummy->next;
    }
};