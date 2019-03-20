#include <iostream>
#include "common.h"
using namespace std;

// Delete a node from a singly linked list.
// The node to be deleted is not the last node in the list.
void remove(shared_ptr<ListNode<int>> L, shared_ptr<ListNode<int>> node) {
	auto succ = node->next;
	node->data = succ->data;
	node->next = succ->next;
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

	remove(L, L);
	cout << "After removal: ";
	print(L);
	
	return 0;
}
