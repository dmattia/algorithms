// My book mentioned that the tower of hanoi problem could be solved via divide-and-conquer,
// so I figured I'd try it. I'll create three vectors to hold pieces. I am choosing vectors because of their easy pop_back
// and push_back functions in constant time.

#include <vector>
#include <iostream>
#define NUMBER_OF_PIECES 10

std::vector<int> towers[3];

int move(int numToMove, int from, int to) {
	int new_moves = 0;

	if(numToMove == 1) {
		new_moves++;
		towers[to].push_back(towers[from].back());
		towers[from].pop_back();
		return new_moves;
	}

	new_moves += move(numToMove-1,from,3-from-to);
	new_moves += move(1,from,to);
	new_moves += move(numToMove-1,3-from-to,to);
	return new_moves;
}

int main() {
	// add ten descending pieces to column 0;
	for(int i = NUMBER_OF_PIECES; i > 0; --i) towers[0].push_back(i);

	std::cout << move(NUMBER_OF_PIECES,0,2) << std::endl;
}


