#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
public:
	void enqueue(const T& t) {
		A.push(t);
	}

	T dequeue() {
		if (B.empty()) {
			// Move all elements from A to B.
			while (!A.empty()) {
				B.push(A.top());
				A.pop();
			}
		}

		if (!B.empty()) {
			T t = B.top();
			B.pop();
			return t;
		}
		
		// If A is also empty, throw an exception.
		throw length_error("Empty queue!");
	}

private:
	stack<T> A, B; // push to A, pop from B.
};

int main() {
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	
	q.enqueue(5);
	cout << q.dequeue() << endl;
	q.enqueue(6);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	return 0;
}
