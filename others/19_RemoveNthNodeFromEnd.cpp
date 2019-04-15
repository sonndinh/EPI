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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head, *prev = nullptr;
        for (int i = 1; i <= n; ++i) {
            fast = fast->next;
        }
        
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev) {
            prev->next = slow->next;
            return head;
        }
        // If prev is null, n-th element from the end is the first element.
        return head->next;
    }
};
