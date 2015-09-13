#include "List.h"
#include <iostream>

int main() {
	List<int> a;
	a.push_front(5);
	a.push_front(6);

	std::cout << "The size is: " << a.size() << std::endl;
	
	a.printList();
	return 0;
}
