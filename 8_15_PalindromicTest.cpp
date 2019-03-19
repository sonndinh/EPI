#include <iostream>
#include "common.h"
using namespace std;

shared_ptr<ListNode<int>> reverse(const shared_ptr<ListNode<int>> head) {
	auto iter = head->next;
	auto curr_head = head; // Pointer to the head of the reversed list.
	while (iter) {
		auto tmp = iter->next;
		head->next = iter->next;
		iter->next = curr_head;
		curr_head = iter;
		iter = tmp;
	}
	return curr_head;
}

bool palindromic(shared_ptr<ListNode<int>> L) {
	int len = 0;
	auto curr = L;
	while (curr) {
		len++;
		curr = curr->next;
	}

	curr = L;
	int half_len = len/2; // Length of the left and right sublist.
	while (half_len--) {
		curr = curr->next;
	}
	auto right_head = curr;
	if (len % 2 == 1) right_head = curr->next;
	
	auto ret = reverse(right_head);
	right_head = ret;
	auto left_head = L;
	bool is_palindromic = true;
	while (left_head && right_head) {
		if (left_head->data != right_head->data) {
			is_palindromic = false;
			break;
		}
		left_head = left_head->next;
		right_head = right_head->next;
	}
	// Reverse the right half back to the original one.
	// The predecessor of the first node on the right sublist still
	// points to it, so we are good.
	reverse(ret);
	return is_palindromic;
}

// Print the list for sanity check.
void print(shared_ptr<ListNode<int>> L) {
	while (L) {
		if (L->next)
			cout << L->data << "==>";
		else
			cout << L->data << endl;
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
	n4->data = 2; n4->next = n5;
	n5->data = 1; n5->next = nullptr;

	bool ret = palindromic(L);
	cout << "Input linked list is " << (ret ? "palindromic!" : "NOT palindromic!") << endl;
	cout << "Final list: ";
	print(L);
	
	return 0;
}
