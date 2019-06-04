#include <iostream>
#include <bitset>
using namespace std;

// States of a chess board is encoded using 64 x 4 bits.
// Each square needs 4 bits to encode. 
using State = bitset<256>;

// Input includes a state, hashcode for that state, a move.
// Output is the hashcode for the updated state.
size_t hash_func(State s, size_t hashcode, int move) {
	
}

int main() {
	return 0;
}
