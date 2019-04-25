/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    vector<int> tmp;
    int next_idx = 0;
    
    void visit(const vector<NestedInteger>& A) {
        for (vector<NestedInteger>::const_iterator it = A.cbegin(); it != A.cend(); ++it) {
            if (it->isInteger())
                tmp.push_back(it->getInteger());
            else 
                visit(it->getList());
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        visit(nestedList);
    }

    int next() {
        return tmp[next_idx++];
    }

    bool hasNext() {
        return (next_idx < tmp.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
