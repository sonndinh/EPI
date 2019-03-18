#include <iostream>
#include <utility>
#include "common.h"
using namespace std;

// Reverse a sublist of k entries.
// Return the first entry and the first entry of the next sublist.
pair<shared_ptr<ListNode<int>>, shared_ptr<ListNode<int>>> reverse_helper(shared_ptr<ListNode<int>> L, int k) {
	int i = 1;
	auto iter = L->next;
	auto head = L;
	
	while (i++ < k) {
		auto tmp = iter->next;
		L->next = tmp;
		iter->next = head;
		head = iter;
		iter = tmp;
	}
	return make_pair(head, iter);
}

// Reverse k entries at a time, and leave the last n mod k entries intact.
shared_ptr<ListNode<int>> reverse(shared_ptr<ListNode<int>> L, int k) {
	if (k <= 1 || L == nullptr) return L;
	
	shared_ptr<ListNode<int>> head = L;
	bool first_sublist = true;
	shared_ptr<ListNode<int>> global_head = nullptr, prev = nullptr;
	while (true) {
		int i = 1;
		bool can_reverse = false;
		shared_ptr<ListNode<int>> tmp = head;
		while (tmp->next) {
			if (++i == k) {
				can_reverse = true;
				break;
			}
			tmp = tmp->next;
		}

		if (can_reverse) {
			// Reverse k entries. Return the head of the reversed sublist.
			auto ret = reverse_helper(head, k);
			if (first_sublist) {
				global_head = ret.first;
				first_sublist = false;
				prev = head;
			} else {
				prev->next = ret.first;
			}

			// Update the head for the next sublist.
			head = ret.second;
			cout << "Head entry: " << head->data << endl;
		} else {
			// Keep the last n mod k entries intact.
			break;
		}
	}
	
	return global_head;
}

void print(shared_ptr<ListNode<int>> L) {
	while (L) {
		if (L->next) {
			cout << L->data << " ==> ";
		} else {
			cout << L->data << endl;
		}
		L = L->next;
	}
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
	n5->data = 5; n5->next = nullptr;

	auto ret = reverse(L, 3);
	print(ret);
	
	return 0;
}
