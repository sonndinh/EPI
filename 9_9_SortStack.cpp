#include <iostream>
#include <stack>
using namespace std;

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

// To execute C++, please define "int main()"
int main() {
    stack<int> s;
    for (int x : {8, 5, 1, 4, 6, 9, 1, 4, 2}) {
        s.push(x);
    }

    sort_stack(s);
    cout << "Output:" << endl;
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
