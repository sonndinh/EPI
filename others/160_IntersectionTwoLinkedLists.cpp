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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) 
            return nullptr;
        
        int countA = 0, countB = 0;
        ListNode *currA = headA, *currB = headB;
        while (currA) {
            ++countA;
            if (currA->next)
                currA = currA->next;
            else 
                break;
        }
        
        while (currB) {
            ++countB;
            if (currB->next)
                currB = currB->next;
            else 
                break;
        }
        // No intersection.
        if (currA != currB)
            return nullptr;
        
        ListNode *long_list = countA > countB ? headA : headB;
        ListNode *short_list = long_list == headA ? headB : headA;
        int offset = abs(countA - countB);
        
        // Move the long list offset step ahead.
        while (offset) {
            long_list = long_list->next;
            --offset;
        }
        
        // Move both pointers one step each time.
        while (long_list != short_list) {
            long_list = long_list->next;
            short_list = short_list->next;
        }
        return long_list;
    }
};
