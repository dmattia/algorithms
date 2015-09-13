#include "List.h"
#include <iostream>

int main() {
	List<int> a;
	a.push_front(5);
	a.push_front(6);
	a.push_back(7);

	std::cout << "The size is: " << a.size() << std::endl;
	
	a.printList();
	return 0;
}
