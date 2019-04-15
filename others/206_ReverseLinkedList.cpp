/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *L = head;
        while (head && head->next) {
            ListNode *curr = head->next;
            head->next = curr->next;
            curr->next = L;
            L = curr;
        }
        return L;
    }
};
