#include <iostream>
#include <memory>
#include <unordered_set>
using namespace std;

template<typename T>
struct TreeNode {
	T data;
	shared_ptr<TreeNode<T>> parent;
	TreeNode(int val) : data(val), parent(nullptr) {}
};

shared_ptr<TreeNode<int>> lca(shared_ptr<TreeNode<int>> a, shared_ptr<TreeNode<int>> b) {
	if (!a || !b) return nullptr;
	unordered_set<shared_ptr<TreeNode<int>>> visited;
	
	// Alternately move the two nodes upward.
	while (a || b) {
		if (a) {
			if (visited.count(a) == 0) {
				visited.insert(a);
				a = a->parent;
			} else {
				return a;
			}
		}

		if (b) {
			if (visited.count(b) == 0) {
				visited.insert(b);
				b = b->parent;
			} else {
				return b;
			}
		}
	}
	
	return nullptr;
}

int main() {
	shared_ptr<TreeNode<int>> n1(new TreeNode<int>(1));
	shared_ptr<TreeNode<int>> n2(new TreeNode<int>(2));
	shared_ptr<TreeNode<int>> n3(new TreeNode<int>(3));
	shared_ptr<TreeNode<int>> n4(new TreeNode<int>(4));
	shared_ptr<TreeNode<int>> n5(new TreeNode<int>(5));
	shared_ptr<TreeNode<int>> n6(new TreeNode<int>(6));
	shared_ptr<TreeNode<int>> n7(new TreeNode<int>(7));
	shared_ptr<TreeNode<int>> n8(new TreeNode<int>(8));
	shared_ptr<TreeNode<int>> n9(new TreeNode<int>(9));
	shared_ptr<TreeNode<int>> n0(new TreeNode<int>(0));

	n1->parent = n6;
	n2->parent = n6;
	n3->parent = n7;
	n4->parent = n7;
	n5->parent = n8;
	n7->parent = n8;
	n6->parent = n9;
	n8->parent = n9;
	n9->parent = n0;

	auto ret = lca(n1, n4);
	cout << "LCA of " << n1->data << " and " << n4->data << " is: " << ret->data << endl;
	return 0;
}
