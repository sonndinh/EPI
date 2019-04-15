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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = NULL;
        ListNode *curr = l;
        
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = (l1 != NULL? l1->val:0) + (l2 != NULL? l2->val:0);
            if (carry == 1) sum += 1;
            carry = sum/10;
            sum = sum % 10;
            
            ListNode *n = new ListNode(sum);            
            if (curr == NULL) {
                curr = n;
                l = n;
            } else {
                curr->next = n;
                curr = curr->next;
            }
            l1 = l1 != NULL? l1->next : NULL;
            l2 = l2 != NULL? l2->next : NULL;
        }
        if (carry == 1) {
            ListNode *n = new ListNode(carry);
            curr->next = n;
        }
        
        return l;
    }
};
