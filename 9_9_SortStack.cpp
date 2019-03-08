#include <iostream>
#include <stack>
using namespace std;

// Sort a stack using a temporary stack.
void sort_stack(stack<int>& s) {
    stack<int> tmp;
    while (!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }
    
    while (!tmp.empty()) {
        int x = tmp.top();
        tmp.pop();
        int count = 0;
        while (!s.empty() && s.top() > x) {
            tmp.push(s.top());
            s.pop();
            count++;
        }
        s.push(x);
        for (int i = 0; i < count; i++) {
            s.push(tmp.top());
            tmp.pop();
        }
    }
}

// Insert t to an already sorted sub-stack.
void helper(stack<int>& s, int t) {
    if (s.empty() || s.top() <= t) {
        s.push(t);
    } else {
        int x = s.top();
        s.pop();
        helper(s, t);
        s.push(x);
    }
}

// Sort a stack without explicitly using another data structure.
void sort_stack2(stack<int>& s) {
    if (s.empty()) return;
    int t = s.top();
    s.pop();
    sort_stack2(s);
    helper(s, t);
}

// To execute C++, please define "int main()"
int main() {
    stack<int> s;
    for (int x : {8, 5, 1, 4, 6, 9, 1, 4, 2}) {
        s.push(x);
    }

    sort_stack2(s);
    cout << "Output:" << endl;
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
