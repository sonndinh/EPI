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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        if (l1 && !l2) return l1;
        if (!l1 && l2) return l2;
        
        ListNode *l = nullptr, *curr = nullptr;
        while (l1 && l2) {
            ListNode *tmp = nullptr;
            if (l1->val < l2->val) {
                tmp = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                tmp = new ListNode(l2->val);
                l2 = l2->next;
            }
            
            if (!l) {
                l = tmp;
            } else {
                curr->next = tmp;
            }
            curr = tmp;
        }
        ListNode *remain = l1? l1 : (l2? l2 : nullptr);
        while (remain) {
            ListNode *tmp = new ListNode(remain->val);
            curr->next = tmp;
            curr = tmp;
            remain = remain->next;
        }
        
        return l;
    }
};
