#include <iostream>
#include "common.h"
using namespace std;

void print(shared_ptr<ListNode<int>> L) {
	while (L) {
		cout << L->data << "->";
		L = L->next;
	}
	cout << endl;	
}

// Merge 2 sorted lists.
shared_ptr<ListNode<int>> merge_lists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
	shared_ptr<ListNode<int>> first = L1, second = L2, head = nullptr, curr = nullptr;
	while (L1 && L2) {
		if (L1->data < L2->data) {
			if (!head) {
				head = L1;
				curr = L1;
			} else {
				curr->next = L1;
				curr = curr->next;
			}
			L1 = L1->next;
		} else {
			if (!head) {
				head = L2;
				curr = L2;
			} else {
				curr->next = L2;
				curr = curr->next;
			}
			L2 = L2->next;
		}
	}

	// Merge the trailing part.
	if (!L1) {
		curr->next = L2;
	} else {
		curr->next = L1;
	}
	
	return head;
}

// Stable sort a linked list.
shared_ptr<ListNode<int>> sort(shared_ptr<ListNode<int>> L) {
	// Base case.
	if (L == nullptr || L->next == nullptr)
		return L;
	
	shared_ptr<ListNode<int>> slow = L, fast = L, prev = nullptr;
	while (fast && fast->next) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = nullptr;

	// Sort the two halves.
	auto head1 = sort(L);
	auto head2 = sort(slow);
	return merge_lists(head1, head2);
}

int main() {
	shared_ptr<ListNode<int>> L(new ListNode<int>);
	shared_ptr<ListNode<int>> n1(new ListNode<int>);
	shared_ptr<ListNode<int>> n2(new ListNode<int>);
	shared_ptr<ListNode<int>> n3(new ListNode<int>);
	shared_ptr<ListNode<int>> n4(new ListNode<int>);
	shared_ptr<ListNode<int>> n5(new ListNode<int>);
	shared_ptr<ListNode<int>> n6(new ListNode<int>);
	shared_ptr<ListNode<int>> n7(new ListNode<int>);

	L->data = 7; L->next = n1;
	n1->data = 3; n1->next = n2;
	n2->data = 8; n2->next = n3;
	n3->data = 1; n3->next = n4;
	n4->data = 4; n4->next = n5;
	n5->data = 2; n5->next = n6;
	n6->data = 10; n6->next = n7;
	n7->data = 0; n7->next = nullptr;

	auto ret = sort(L);
	print(ret);
	return 0;
}
