#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T> > next;
};

shared_ptr<ListNode<int> > reverse(shared_ptr<ListNode<int> > L) {
	if (!L || !(L->next)) return L;

	shared_ptr<ListNode<int> > prev = L;
	L = L->next;
	shared_ptr<ListNode<int> > next = L->next;
	prev->next = NULL;

	while (!(L->next)) {
		L->next = prev;
		prev = L;
		L = next;
		next = next->next;
	}

	L->next = prev;
	return L;
}
