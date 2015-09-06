//This program will test if any subset of a vector adds to a value or not 
#include <vector>
#include <iostream>
#include <iterator>
#include "assert.h"

// Returns the sum of a vector in O(n) time
int sum(std::vector<int> &vect) {
	int sum = 0;
	std::vector<int>::iterator it = vect.begin();
	while(it != vect.end()) {
		sum += *it;
		++it;
	}
	return sum;
}

// Returns if a vector vect[lower_bound...upper_bound] can be partitioned
// in such away that the sum of a partition equals the key value
int addsTo(std::vector<int> &vect, int lower_bound, int upper_bound, int key) {
	if(key==0) return 1;
	if(key<0 | upper_bound < lower_bound) return 0;

	assert(key>0);
	int b1,b2; //temporary boolean values to store the result of the two subcases

	//First subcase: vect[upper_bound] is in the subarray
	b1 = addsTo(vect,lower_bound,upper_bound-1,key-vect[upper_bound]);
	if(b1) {
		return 1;
	}
	
	//Second subcase: vect[upper_bound] is not in the subarray
	b2 = addsTo(vect,lower_bound,upper_bound-1,key);
	if(b2) {
		return 1;
	}

	//Both subcases failed. This means that this key cannot be found as the sum of any subset
	return 0;
}

// Returns a boolean value whether or not
// two subarrays exist in vect that partition
// vect and that sum to the same value
int can_end_in_a_tie(std::vector<int> &vect) {
	if(sum(vect) % 2) return 0;
	int total = sum(vect) / 2;

	// The partitions exist if any subarray exists that adds
	// to exactly one half of the sum value. If one such subarray
	// exists, then all other elements must also sum to this value
	return addsTo(vect,0,vect.size()-1,total);
}

// Performs the same effect as can_end_in_a_tie,
// but does so with O(n*sum) time and space
int can_end_in_a_tie_improved(std::vector<int> &vect) {
	int total = sum(vect); //O(n)
	int n = vect.size();   //O(1)
	if(total%2) return 0; //if total is odd, no tie can possible occur
	total /= 2; //we only care about adding to the half total
	
	// create an n x total table
	int **table = new int*[n];
	for(int i=0; i < n; ++i) {
		table[i] = new int[total+1];
	}
	//Min of table is table[0][0]. max is table[n-1][total]

	// Iterate through the table and determine if that sum(column) is possible
	// using the first i values of the vector(row) The final value when sum=total
	// and i=n will be weather or not a tie can occur
	for(int i=1; i <= n; ++i) {
		for(int sum=0; sum <= total; ++sum) {
			//Check if top row. If it is, only vect[0] and 0 can be found as a sum
			if(i==1) {
				table[i-1][sum] = 0;
				if(sum==0 || sum==vect[i-1]) table[i-1][sum] = 1;
			} else {
				// Not in the top row. Value will be true if the value directly
				// above in the table is true or if the value with the sum of vect[i]
				// subtracted is true.
				table[i-1][sum] = 0;
				if(table[i-2][sum]==1) {
					table[i-1][sum] = 1;
				} else if(sum-vect[i-1] >= 0 && table[i-2][sum-vect[i-1]]) {
					table[i-1][sum] = 1;
				}
			}
		}
	}

	return table[n-1][total];
}

int main() {
	std::vector<int> myVect;
	myVect.push_back(9);
	myVect.push_back(6);
	myVect.push_back(8);
	myVect.push_back(12);
	myVect.push_back(24);
	myVect.push_back(7);
	myVect.push_back(4);
	myVect.push_back(20);
	myVect.push_back(11);
	myVect.push_back(4);
	myVect.push_back(5);
	myVect.push_back(3);
	myVect.push_back(7);
	myVect.push_back(8);
	myVect.push_back(29);
	myVect.push_back(12);
	myVect.push_back(6);
	myVect.push_back(3);
	myVect.push_back(47);
	myVect.push_back(3);
	myVect.push_back(4);
	myVect.push_back(12);
	myVect.push_back(9);
	myVect.push_back(10);
	myVect.push_back(10);
	myVect.push_back(4);
	myVect.push_back(4);
	myVect.push_back(36);
	myVect.push_back(23);
	myVect.push_back(25);
	myVect.push_back(3);
	myVect.push_back(5);
	myVect.push_back(10);
	myVect.push_back(11);
	myVect.push_back(7);
	myVect.push_back(8);
	myVect.push_back(21);
	myVect.push_back(4);
	myVect.push_back(8);
	myVect.push_back(10);
	myVect.push_back(13);
	myVect.push_back(7);
	myVect.push_back(5);
	myVect.push_back(16);
	myVect.push_back(13);
	myVect.push_back(8);
	myVect.push_back(4);
	myVect.push_back(11);
	myVect.push_back(3);
	myVect.push_back(3);
	myVect.push_back(3);
	std::cout << can_end_in_a_tie_improved(myVect) << std::endl;
	
	/*myVect.push_back(2);
	myVect.push_back(3);
	myVect.push_back(7);
	myVect.push_back(8);
	myVect.push_back(10);
	std::cout << can_end_in_a_tie_improved(myVect) << std::endl;
	*/
}
