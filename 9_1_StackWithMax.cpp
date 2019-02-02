#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
class Stack {
private:
	size_t capacity;
	size_t size;
	pair<T, T> *stack;
	
public:
	Stack(size_t capacity) {
		this->capacity = capacity;
		stack = new pair<T, T>[capacity];
		size = 0;
	}
	
	~Stack() {
		delete[] stack;
	}

	void push(const T& t) {
		if (size == capacity) {
			pair<T, T> *old = stack;
			stack = new pair<T, T>[capacity*2];
			for (size_t i = 0; i < capacity; i++) {
				stack[i] = old[i];
			}
			capacity *= 2;
			delete[] old;
		} 

		pair<T, T> p;
		p.first = t;
		p.second = size == 0? t : (t > stack[size-1].second? t : stack[size-1].second);
		stack[size] = p;
		++size;
	}
	
	T pop() {
		if (size == 0) {
			return T();
		}

		return stack[--size].first;
	}
	
	bool empty() {
		return (size == 0);
	}

	size_t length() {
		return size;
	}

	size_t cap() {
		return capacity;
	}

	T max() {
		if (size == 0) {
			return T();
		}

		return stack[size-1].second;
	}
};

int main() {
	Stack<int> stk(2);

	cout << "Capacity: " << stk.cap() << endl;	
	stk.push(11);
	stk.push(7);
	stk.push(15);
	stk.push(20);
	cout << "Size: " << stk.length() << ". Max value: " << stk.max() << endl;

	stk.pop();
	stk.pop();
	cout << "Size: " << stk.length() << ". Max value: " << stk.max() << endl;

	stk.pop();
	stk.pop();
	cout << "Nonexisting element: " << stk.pop() << endl;

	return 0;
}
