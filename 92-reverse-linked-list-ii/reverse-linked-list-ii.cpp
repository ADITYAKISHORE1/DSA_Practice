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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l, *r;
        ListNode *pl, *fr;
        ListNode* ptr = new ListNode(-1000);
        ptr->next = head;
        head = ptr;
        int cnt = 0;
        while (ptr != nullptr) {
            if (ptr->next != nullptr and cnt == left - 1) {
                pl = ptr;
                l = ptr->next;
            }
            if (cnt == right) {
                r = ptr;
                fr = ptr->next;
            }
            ptr = ptr->next;
            cnt++;
        }
        ptr = l;
        ListNode* prev = fr;
        while (ptr != fr) {
            ListNode* t = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = t;
        }
        if (pl != nullptr)
            pl->next = prev;
        return head->next;
    }
};