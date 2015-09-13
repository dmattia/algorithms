#include "List.h"
#include <iostream>

int main() {
	List<int> a;
	a.push_front(1);
	a.insert(2,1);
	a.insert(0,0);

	std::cout << "The size is: " << a.size() << std::endl;
	
	a.printList();
	return 0;
}
