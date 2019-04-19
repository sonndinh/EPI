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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head, *fast = head;
        
        while (fast) {
            fast = fast->next;
            if (fast == slow) return true;
            if (fast) {
                fast = fast->next;
                if (fast == slow) return true;
            }
            slow = slow->next;
        }
        return false;
    }
};
