#include <iostream>
#include "common.h"
using namespace std;

// Reverse a sublist of element s-th to f-th, inclusive from a single linked list.
shared_ptr<ListNode<int>> reverse(shared_ptr<ListNode<int>> L, int s, int f) {
	if (s >= f) return L;
	
	int i = 1;
	shared_ptr<ListNode<int>> curr = L, before = nullptr, last = nullptr, next1 = nullptr, next2 = nullptr;
	
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

	L = reverse(L, 2, 5);
	print(L);
	return 0;
}
