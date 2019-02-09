#include <memory>

template <typename T>
struct ListNode {
	T data;
	std::shared_ptr<ListNode<T>> next;
};

template <typename T>
struct BinaryTreeNode {
	T data;
	std::unique_ptr<BinaryTreeNode<T>> left, right;
};
