// This program finds the maxiumum consecutive subarray in any given array.  

#include "time.h"
#include "functions.h"
#include <iostream>

static double time_consumed = 0;

int main(int argc, const char * argv[]) {
    clock_t start, end;
    
    std::vector<double> a;
    for(int i = 0; i < 20; ++i) a.push_back(rand() % 101 - 50);
    
    start = clock();
    struct subarray result = divide_and_conquer(a,0,(int)a.size()-1);
    //struct subarray result = linear_time(a);
    print_struct(result);
    end = clock();

	for(int i = 0; i < a.size(); ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

    time_consumed += (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << time_consumed << std::endl;
    
    return 0;
}
