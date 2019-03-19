#include <iostream>
#include <unordered_set>
#include "common.h"
using namespace std;

// Return the first overlapping node if exist, null otherwise.
shared_ptr<ListNode<int>> overlapping(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
	unordered_set<shared_ptr<ListNode<int>>> nodes;
	auto curr = L1;
	while (curr) {
		nodes.emplace(curr);
		curr = curr->next;
	}

	curr = L2;
	while (curr) {
		if (nodes.find(curr) != nodes.cend())
			return curr;
		curr = curr->next;
	}
	return nullptr;
}

int main() {
	shared_ptr<ListNode<int>> L1(new ListNode<int>);
	shared_ptr<ListNode<int>> n2(new ListNode<int>);
	shared_ptr<ListNode<int>> n3(new ListNode<int>);
	shared_ptr<ListNode<int>> n4(new ListNode<int>);
	shared_ptr<ListNode<int>> n5(new ListNode<int>);
	L1->data = 1; L1->next = n2;
	n2->data = 2; n2->next = n3;
	n3->data = 3; n3->next = n4;
	n4->data = 4; n4->next = n5;
	n5->data = 5; n5->next = nullptr;

	shared_ptr<ListNode<int>> L2(new ListNode<int>);
	L2->data = 10; L2->next = n3;
	auto ret = overlapping(L1, L2);
	if (ret) {
		cout << "Overlapping node: " << ret->data << "!" << endl;
	} else {
		cout << "No overlapping node!" << endl;
	}

	return 0;
}
