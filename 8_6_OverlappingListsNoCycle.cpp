#include <iostream>
#include <unordered_set>
#include "common.h"
using namespace std;

// Return the first overlapping node if exist, null otherwise.
shared_ptr<ListNode<int>> overlap(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
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

// O(n^2) time. No extra space
shared_ptr<ListNode<int>> overlap2(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
	auto curr1 = L1;
	while (curr1) {
		auto curr2 = L2;
		while (curr2) {
			if (curr2 == curr1)
				return curr1;
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	return nullptr;
}

shared_ptr<ListNode<int>> overlap3(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
	auto curr1 = L1;
	auto curr2 = L2;
	int count1 = 0, count2 = 0;
	while (curr1) {
		count1++;
		curr1 = curr1->next;
	}
	while (curr2) {
		count2++;
		curr2 = curr2->next;
	}

	auto longer = count1 > count2 ? L1 : L2;
	auto shorter = count1 <= count2 ? L1 : L2;	
	int len_diff = count1 > count2 ? count1 - count2 : count2 - count1;
	// Advance the longer list by the length difference.
	while (len_diff--) {
		longer = longer->next;
	}

	while (longer) {
		if (longer == shorter) return longer;
		longer = longer->next;
		shorter = shorter->next;
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
	L2->data = 10; L2->next = n2;
	auto ret = overlap3(L1, L2);
	if (ret) {
		cout << "Overlapping node: " << ret->data << "!" << endl;
	} else {
		cout << "No overlapping node!" << endl;
	}

	return 0;
}
