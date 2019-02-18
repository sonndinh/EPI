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

template <typename T>
struct BinaryTreeNode2 {
	T data;
	std::shared_ptr<BinaryTreeNode2<T>> parent;
};

template <typename T>
struct BSTNode {
	T data;
	std::unique_ptr<BSTNode<T>> left, right;
};
