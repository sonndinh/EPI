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
    struct Compare {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Use min-heap to find minimum among k nodes.
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;
     
        for (ListNode *tmp : lists) {
            if (tmp)
                min_heap.push(tmp);
        }
        
        ListNode *head = nullptr, *curr = nullptr;
        while (!min_heap.empty()) {
            ListNode *next_node = min_heap.top();
            if (!head) {
                head = next_node;
                curr = next_node;
            } else {
                curr->next = next_node;
                curr = next_node;
            }
            
            min_heap.pop();
            if (next_node->next)
                min_heap.push(next_node->next);
        }
        return head;
    }
};
