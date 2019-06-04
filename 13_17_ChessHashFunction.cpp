#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

// States of a chess board is encoded using 64 x 4 bits.
// Each square needs 4 bits to encode. 
using state_t = bitset<4>[64];
using code_t = unsigned long long;

const int prime = 2;

// Input includes a state, hashcode for that state, a move from a quare to a new square.
// @from and @to must be from 0 to 63 for valid squares on the chess board.
// Output is the hashcode for the updated state.
code_t hash_func(state_t state, code_t hashcode, int from, int to) {
	const bitset<4> blank_state(0);
	bitset<4> orig_source_square = state[from], orig_target_square = state[to];
	bitset<4> updated_source_square = blank_state, updated_target_square = orig_source_square;
	
	return hashcode - orig_source_square.to_ullong() * pow(prime, from)
		- orig_target_square.to_ullong() * pow(prime, to)
		+ updated_source_square.to_ullong() * pow(prime, from)
		+ updated_target_square.to_ullong() * pow(prime, to);
}

int main() {
	return 0;
}
