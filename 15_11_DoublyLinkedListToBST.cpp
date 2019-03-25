#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T>> prev, next;
};

// Convert a sublist started at a given node into a BST. Return the root of the BST.
// Update the pointer to the head of the next sublist.
shared_ptr<ListNode<int>> convert_helper(shared_ptr<ListNode<int>>& head, int n) {
	if (n <= 0) {
		return nullptr;
	}
	
	auto left_root = convert_helper(head, n/2);
	auto root = head;
	head = head->next;
	auto right_root = convert_helper(head, n - n/2 - 1);
	root->prev = left_root;
	root->next = right_root;

	return root;
}

// Convert a sorted doubly linked list to a BST.
shared_ptr<ListNode<int>> linked_list_to_bst(shared_ptr<ListNode<int>> L) {
	auto curr = L;
	int n = 0;
	while (curr) {
		++n;
		curr = curr->next;
	}

	return convert_helper(L, n);
}

// Inorder traveral.
void print_bst(shared_ptr<ListNode<int>> node) {
	if (!node) return;
	print_bst(node->prev);
	cout << node->data << " ";
	print_bst(node->next);
}

int main() {
	shared_ptr<ListNode<int>> n1(new ListNode<int>{1, nullptr, nullptr});
	shared_ptr<ListNode<int>> n2(new ListNode<int>{2, nullptr, nullptr});
	shared_ptr<ListNode<int>> n3(new ListNode<int>{3, nullptr, nullptr});
	shared_ptr<ListNode<int>> n4(new ListNode<int>{4, nullptr, nullptr});
	shared_ptr<ListNode<int>> n5(new ListNode<int>{5, nullptr, nullptr});
	shared_ptr<ListNode<int>> n6(new ListNode<int>{6, nullptr, nullptr});
	shared_ptr<ListNode<int>> n7(new ListNode<int>{7, nullptr, nullptr});
	n1->next = n2;
	n2->prev = n1; n2->next = n3;
	n3->prev = n2; n3->next = n4;
	n4->prev = n3; n4->next = n5;
	n5->prev = n4; n5->next = n6;
	n6->prev = n5; n6->next = n7;
	n7->prev = n6;

	auto root = linked_list_to_bst(n1);
	print_bst(root); cout << endl;
	return 0;
}
