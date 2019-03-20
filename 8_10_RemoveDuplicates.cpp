#include <iostream>
#include "common.h"
using namespace std;

// Remove duplicates from a sorted list.
void remove_dup(shared_ptr<ListNode<int>> L) {
	auto curr = L;

	while (curr && curr->next) {
		if (curr->data == curr->next->data) {
			curr->next = curr->next->next;
		} else {
			curr = curr->next;
		}
	}
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
	n2->data = 1; n2->next = n3;
	n3->data = 1; n3->next = n4;
	n4->data = 4; n4->next = n5;
	n5->data = 5; n5->next = nullptr;

	remove_dup(L);
	print(L);
	
	return 0;
}
