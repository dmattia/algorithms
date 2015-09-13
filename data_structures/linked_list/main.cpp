#include "List.h"
#include <iostream>

int main() {
	List<int> a;
	a.push_front(1);
	a.insert(2,1);
	a.insert(0,0);
	a.push_back(3);

	a.printList();
	std::cout << "The size is: " << a.size() << std::endl;
	std::cout << "The back is: " << a.back()->value << std::endl;
	
	return 0;
}
