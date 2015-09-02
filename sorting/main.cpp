#include "time.h"
#include "sorts.h"
#include <iostream>

static double time_consumed = 0;

int main(int argc, const char * argv[]) {
    clock_t start, end;
    
    std::vector<int> a,b,result;
    for(int i = 0; i < 5000000; ++i) a.push_back(rand() % 100);

    start = clock();
    {
	//merge_sort(a);
        //insertion_sort(a);
        //bubble_sort(a);
        //improved_merge_sort(a);
        std::sort(a.begin(),a.end());
    }
    end = clock();
    time_consumed += (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << time_consumed << std::endl;
    
    return 0;
}

