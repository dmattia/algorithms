#include "time.h"
#include "sorts.h"
#include <iostream>

static double time_consumed = 0;

int main(int argc, const char * argv[]) {
    clock_t start, end;
    
    std::vector<int> a,b,result;
    for(int i = 0; i < 100000; ++i) a.push_back(rand()%100);

    start = clock();
    {
	//merge_sort(a);
        //insertion_sort(a,0,(int)a.size());
        //bubble_sort(a);
        merge_sort(a,0,(int)a.size());
		//merge_parallel(a,0,(int)a.size(),0);
        //std::sort(a.begin(),a.end());
    }
    end = clock();
    time_consumed += (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << time_consumed << std::endl;
    
    return 0;
}
