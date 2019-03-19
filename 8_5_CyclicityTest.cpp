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
	shared_ptr<ListNode<int>> iter1 = L, iter2;
	while (iter1) {
		iter2 = iter1->next;
		while (iter2) {
			if (iter2 == iter1) return iter1;
			iter2 = iter2->next;
		}
		if (iter2 == nullptr) break;
		iter1 = iter1->next;
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

	auto ret = cyclic2(L);
	if (ret) {
		cout << "Cycle starts at node " << ret->data << "!" << endl;
	} else {
		cout << "No cycle found!" << endl;
	}
	
	return 0;
}
