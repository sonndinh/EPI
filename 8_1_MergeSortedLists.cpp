#include <iostream>
#include <memory>
#include <cstddef>

using namespace std;

template <typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T> > next;
};

shared_ptr<ListNode<int> > merge(shared_ptr<ListNode<int> > L, shared_ptr<ListNode<int> > F) {
	if (!L) return F;
	if (!F) return L;

	shared_ptr<ListNode<int> > M;
	shared_ptr<ListNode<int> > curr;

	if (L->data < F->data) {
		M = L;
		L = L->next;
	} else {
		M = F;
		F = F->next;
	}
	curr = M;

	while (L || F) {
		if (!L) {
			curr->next = F;
			break;
		} else if (!F) {
			curr->next = L;
			break;
		}

		if (L->data < F->data) {
			curr->next = L;
			L = L->next;
		} else {
			curr->next = F;
			F = F->next;
		}
		curr = curr->next;
	}

	return M;
}
