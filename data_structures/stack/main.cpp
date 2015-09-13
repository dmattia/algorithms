#include "Stack.h"
#include <iostream>

int main() {
	Stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);

	std::cout << "Next is: " << a.peek() << std::endl;
	std::cout << "Top is: " << a.top() << std::endl;

	while(!a.empty()) {
		std::cout << a.pop() << std::endl;
	}

	std::cout << "The size is: " << a.size() << std::endl;
}
