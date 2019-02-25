#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;
using LRU = list<pair<int, double>>;

class Cache {
public:
	Cache(size_t cap) {
		capacity = cap;
	}
	
	double lookup(int isbn) {
		unordered_map<int, LRU::iterator>::iterator it = isbn_to_iter.find(isbn);
		if (it == isbn_to_iter.end())
			throw length_error("Nonexist isbn!");

		double price = it->second->second;
		lru.emplace_front(isbn, price);
		isbn_to_iter[isbn] = lru.begin();
		lru.erase(it->second);
		return price;
	}

	void insert(int isbn, double price) noexcept {
		if (lru.size() == capacity) {
			// Evict the least recently used item.
			isbn_to_iter.erase(lru.back().first);;
			lru.pop_back();
		}
		// Insert to front.
		lru.emplace_front(isbn, price);
		isbn_to_iter[isbn] = lru.begin();
	}

	void erase(int isbn) {
		unordered_map<int, LRU::iterator>::iterator it = isbn_to_iter.find(isbn);
		if (it == isbn_to_iter.end())
			throw length_error("Nonexist isbn!");

		isbn_to_iter.erase(isbn);
		lru.erase(it->second);
	}
	
private:
	size_t capacity;
	unordered_map<int, LRU::iterator> isbn_to_iter;
	LRU lru;
};

int main() {
	size_t cap = 8;
	Cache cache(cap);
	for (int i = 1; i <= cap; i++) {
		cache.insert(i, 5.0*i);
	}

	for (int i = 1; i <= cap; i++) {
		cout << "Price of book " << i << ": " << cache.lookup(i) << endl;
	}

	for (int i = 1; i <= cap + 1; i++) {
		cout << "Erasing book " << i << endl;
		cache.erase(i);
	}
	
	return 0;
}
