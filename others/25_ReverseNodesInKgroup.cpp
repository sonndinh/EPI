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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode *curr = head;
        int n = 0;
        while (curr) {
            ++n;
            curr = curr->next;
        }
        
        ListNode *ret = head, *next = nullptr, *prev = nullptr;
        int times = n/k;
        while (times > 0) {
            int K = k;
            ListNode *head_new;
            if (!next)
                head_new = head;
            else 
                head_new = next;
            head = head_new;
            next = head_new->next;
            while (--K > 0) {
                head->next = next->next;
                next->next = head_new;
                head_new = next;
                next = head->next;
            }
            if (prev)
                prev->next = head_new;
            prev = head;
            if (times == n/k) {
                ret = head_new;
            }
            --times;
        }
        
        return ret;
    }
};
