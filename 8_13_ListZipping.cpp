#include <iostream>
#include "common.h"
using namespace std;

// Zip a singly linked-list.
shared_ptr<ListNode<int>> zip(const shared_ptr<ListNode<int>>& L) {
	if (L == nullptr || L->next == nullptr)
		return L;

	shared_ptr<ListNode<int>> slow = L, fast = L;
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	if (fast && fast->next == nullptr) {
		slow = slow->next;
	}

	// Reverse the second half of the list.
	shared_ptr<ListNode<int>> L2 = slow, head = L2;
	while (L2->next != nullptr) {
		// Iteratively insert L2->next to the head.
		auto next = L2->next;
		L2->next = next->next;
		next->next = head;
		head = next;
	}

	// Combine the two sublists.
	auto first = L, second = head;
	while (first != nullptr && second != nullptr) {
		auto tmp = first->next;
		first->next = second;
		first = second;
		second = tmp;
	}
	if (first)
		first->next = nullptr;
	if (second)
		second->next = nullptr;

	return L;
}

int main() {
	shared_ptr<ListNode<int>> L(new ListNode<int>);
	shared_ptr<ListNode<int>> n1(new ListNode<int>);
	shared_ptr<ListNode<int>> n2(new ListNode<int>);
	shared_ptr<ListNode<int>> n3(new ListNode<int>);
	shared_ptr<ListNode<int>> n4(new ListNode<int>);
	shared_ptr<ListNode<int>> n5(new ListNode<int>);
	L->data = 0; L->next = n1;
	n1->data = 1; n1->next = n2;
	n2->data = 2; n2->next = n3;
	n3->data = 3; n3->next = n4;
	n4->data = 4; n4->next = n5;
	n5->data = 5; n5->next = nullptr;

	auto ret = zip(L);
	while (L != nullptr) {
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
	
	return 0;
}
