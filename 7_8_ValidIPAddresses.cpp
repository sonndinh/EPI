#include <iostream>
#include <vector>
#include <string>
using namespace std;

void helper(vector<string>& v, string ip, int start, int count, string curr) {
    if (count == 0) {
        if (start < (int)ip.size() && stoi(ip.substr(start)) <= 255) {
            curr += ip.substr(start);
            v.push_back(curr);
        }
        return;
    }
    
    // Each number has at most 3 digits in each number.
    for (int i = 1; i <= 3; i++) {
        string next = ip.substr(start, i);
        if (stoi(next) <= 255) {
            string tmp = curr + next + ".";
            helper(v, ip, start + i, count - 1, tmp);
        }
    }
}

// Compute all valid IP addresses by adding '.''s to correct positions.
// E.g., "19216811" ==> "192.168.1.1"
vector<string> ip_addresses(string ip) {
    vector<string> ret;
    helper(ret, ip, 0, 3, "");
    return ret;
}

// To execute C++, please define "int main()"
int main() {
	//    string ip = "19216811";
	string ip = "255255255255";
    vector<string> ret = ip_addresses(ip);
    for (string s : ret) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
