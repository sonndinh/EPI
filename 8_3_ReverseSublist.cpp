#include <iostream>
#include "common.h"
using namespace std;

// Reverse a sublist of element s-th to f-th, inclusive from a single linked list.
shared_ptr<ListNode<int>> reverse(shared_ptr<ListNode<int>> L, int s, int f) {
	if (s >= f) return L;
	
	int i = 1;
	
	shared_ptr<ListNode<int>> curr = L;
	// Pointers to entry right before the sublist and the last in reversed order.
	shared_ptr<ListNode<int>> before = nullptr, last = nullptr;
	// Pointers to the two next entries in the sublist.
	shared_ptr<ListNode<int>> next1 = nullptr, next2 = nullptr;
	
	while (i <= f && curr) {
		if (i < s) {
			before = curr;
			curr = curr->next;
			i++;
		} else if (i == s) {
			last = curr;
			next1 = curr->next;
			i++;
		} else {
			next2 = next1->next;
			next1->next = curr;
			curr = next1;
			next1 = next2;
			i++;
		}
	}
	if (before) {
		before->next = curr;
	} else {
		before = curr;
		L = before;
	}
	last->next = next1;
	return L;
}

shared_ptr<ListNode<int>> reverse2(shared_ptr<ListNode<int>> L, int s, int f) {
	if (s == f) return L;

	auto dummy_head = make_shared<ListNode<int>> (ListNode<int>{0, L});
	auto sublist_head = dummy_head;
	int k = 1;
	while (k++ < s) {
		sublist_head = sublist_head->next;
	}

	auto sublist_iter = sublist_head->next;
	while (s++ < f) {
		auto tmp = sublist_iter->next;
		sublist_iter->next = tmp->next;
		tmp->next = sublist_head->next;
		sublist_head->next = tmp;
	}
	return dummy_head->next;
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

	L = reverse2(L, 2, 4);
	print(L);
	return 0;
}
