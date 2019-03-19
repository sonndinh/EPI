#include <iostream>
#include <unordered_set>
#include "common.h"
using namespace std;

// Test if a singly linked list is cyclic.
// Return the start of a cycle if one exists, null otherwise.
shared_ptr<ListNode<int>> cyclic(shared_ptr<ListNode<int>> L) {
	// All nodes encountered from the beginning.
	unordered_set<shared_ptr<ListNode<int>>> nodes;
	shared_ptr<ListNode<int>> curr = L, start = nullptr;
	while (curr) {
		if (nodes.find(curr) != nodes.cend()) {
			start = curr;
			break;
		}
		nodes.emplace(curr);
		curr = curr->next;
	}
	return start;
}

// Use 2 iterators. Don't use hash set.
shared_ptr<ListNode<int>> cyclic2(shared_ptr<ListNode<int>> L) {
	if (!L) return L;

	shared_ptr<ListNode<int>> dummy_head = make_shared<ListNode<int>> (ListNode<int>{0, L});
	shared_ptr<ListNode<int>> iter1 = L;
	int count = 1;
	while (iter1) {
		auto iter2 = dummy_head;
		int remain = count;
		while (remain--) {
			iter2 = iter2->next;
			if (iter2 == iter1 && remain > 0) return iter1;
		}
		iter1 = iter1->next;
		count++;
	}
	return nullptr;
}

// Use fast and slow iterators.
shared_ptr<ListNode<int>> cyclic3(shared_ptr<ListNode<int>> L) {
	shared_ptr<ListNode<int>> fast = L, slow = L;

	while (fast && fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			// Count number of nodes in the cycle.
			int num_cycle_nodes = 1;
			auto tmp = slow->next;
			while (tmp != slow) {
				num_cycle_nodes++;
				tmp = tmp->next;
			}

			slow = L; fast = L;
			// Move the fast iterator num_cycle_nodes steps forward.
			while (num_cycle_nodes--) {
				fast = fast->next;
			}

			// Move both slow and fast iterators one-by-one step, until the match.
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return nullptr;
}

int main() {
	shared_ptr<ListNode<int>> L(new ListNode<int>);
	shared_ptr<ListNode<int>> n2(new ListNode<int>);
	shared_ptr<ListNode<int>> n3(new ListNode<int>);
	shared_ptr<ListNode<int>> n4(new ListNode<int>);
	shared_ptr<ListNode<int>> n5(new ListNode<int>);
	L->data = 1; L->next = n2;
	n2->data = 2; n2->next = n3;
	n3->data = 3; n3->next = n4;
	n4->data = 4; n4->next = n5;
	n5->data = 5; //n5->next = nullptr;
	n5->next = n3;

	auto ret = cyclic3(L);
	if (ret) {
		cout << "Cycle starts at node " << ret->data << "!" << endl;
	} else {
		cout << "No cycle found!" << endl;
	}
	
	return 0;
}
