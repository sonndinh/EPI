#include <iostream>
using namespace std;

// Read 4 characters. Return the actual number of characters read.
int read4(char *buf) {
	return 0;
}

// Read n characters.
int read(char *buf, int n) {
	// Remain number of characters to read and the number of characters have been read.
	int remain = n, count = 0;

	// Iteratively read 4 characters and write to the target buffer.
	while (remain > 0) {
		int num = read4(buf + count);
		remain -= num;
		count += num;
		
		// Reach end of file.
		if (num < 4) break;
	}
	
	return (count > n ? n : count);
}

int main() {
	return 0;
}
