#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct Node {
	T data;
	shared_ptr<Node<T>> next; // Pointer to next entry.
	shared_ptr<Node<T>> jump; // Random pointer.
};

void print(shared_ptr<Node<int>> L) {
	while (L) {
		if (L->next) {
			cout << L->data << "," << (L->jump ? L->jump->data : -1) << " ==> ";
		} else {
			cout << L->data << "," << (L->jump ? L->jump->data : -1) << endl;
		}
		L = L->next;
	}
}

shared_ptr<Node<int>> copy(shared_ptr<Node<int>> L) {
	auto curr = L;
	shared_ptr<Node<int>> C = nullptr;

	// Create and interleave clone nodes with the original nodes.
	while (curr) {
		shared_ptr<Node<int>> clone(new Node<int>);
		if (!C) C = clone;
		clone->data = curr->data;
		clone->next = curr->next;
		curr->next = clone;
		curr = curr->next->next;
	}

	// Set correct jump pointers for the clone nodes.
	curr = L;
	auto curr2 = C;
	while (curr) {
		curr2->jump = curr->jump ? curr->jump->next : nullptr;
		curr = curr->next->next;
		if (curr2->next)
			curr2 = curr2->next->next;
	}

	// Split the two lists.
	curr = L; curr2 = C;
	while (curr) {
		curr->next = curr->next->next;
		if (curr2->next)
			curr2->next = curr2->next->next;
		curr = curr->next;
		curr2 = curr2->next;
	}
	return C;
}

int main() {
	shared_ptr<Node<int>> L(new Node<int>);
	shared_ptr<Node<int>> n2(new Node<int>);
	shared_ptr<Node<int>> n3(new Node<int>);
	shared_ptr<Node<int>> n4(new Node<int>);
	shared_ptr<Node<int>> n5(new Node<int>);
	L->data = 1; L->next = n2; L->jump = n4;
	n2->data = 2; n2->next = n3; n2->jump = L;
	n3->data = 3; n3->next = n4; n3->jump = n2;
	n4->data = 4; n4->next = n5; n4->jump = nullptr;
	n5->data = 5; n5->next = nullptr; n5->jump = n3;

	cout << "Original list: "; print(L);
	auto clone = copy(L);
	cout << "Clone list: "; print(clone);

	return 0;
}
