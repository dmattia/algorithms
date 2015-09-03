/* Implements a binary search on a sorted vector */

#include <iostream>
#include <vector>

#define NOT_FOUND -1

template <typename T>
int binary_search(std::vector<T> &a, T search_value, int lower_bound, int upper_bound) {
	if (upper_bound < lower_bound) return NOT_FOUND;

	int middle = (upper_bound + lower_bound) / 2;

	if (a[middle]==search_value) {
		return middle;
	} else 
	if (a[middle] > search_value) {
		return binary_search(a,search_value,lower_bound,middle-1);
	}
	return binary_search(a,search_value,middle+1,upper_bound);
}

int main() {
	std::vector<int> myVect;
	for(int i = 0; i < 10; ++i) myVect.push_back(i);
	for(int i = 20; i < 30; ++i) myVect.push_back(i);

	for(int i = -1; i < 31; ++i) {
		std::cout << "searching for " << i << " found at: " << binary_search(myVect,i,0,myVect.size()-1) << std::endl; 
	}
	
	return 0;
}
