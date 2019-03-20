#include <iostream>
#include "common.h"
using namespace std;

// Remove the k-th last node of a singly linked list.
shared_ptr<ListNode<int>> remove(shared_ptr<ListNode<int>> L, int k) {
	auto slow = L, fast = L;

	// Advance the fast pointer to the k-th node from the beginning.
	while (--k) {
		fast = fast->next;
	}

	shared_ptr<ListNode<int>> prev = nullptr;
	while (fast->next) {
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}

	if (prev)
		prev->next = slow->next;
	else
		L = slow->next;
	return L;
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

	auto ret = remove(L, 5);
	print(ret);
	return 0;
}
