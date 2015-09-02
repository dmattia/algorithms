//Implementation for sorting

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
void merge_sort(std::vector<T> &a,int lower_index,int upper_index) {
    if (upper_index - lower_index < 43) {
		insertion_sort(a,lower_index,upper_index);
        return;
    }
    
	int middle_index = (lower_index + upper_index) / 2;

    merge_sort(a,lower_index,middle_index);
    merge_sort(a,middle_index+1,upper_index);
    merge_vectors(a,lower_index,middle_index,upper_index);
}

template <typename T>
void merge_vectors(std::vector<T> &a, int lower_index, int middle_index, int upper_index) {
	std::vector<T> left(a.begin()+lower_index,a.begin()+middle_index), right(a.begin()+middle_index,a.begin()+upper_index);
	typename std::vector<T>::iterator left_it = left.begin(), right_it = right.begin(), a_it = a.begin()+lower_index;

	while(left_it != left.end() && right_it != right.end()) {
		if(*left_it < *right_it) {
			*a_it = *left_it;
			++left_it;
		} else {
			*a_it = *right_it;
			++right_it;
		}
		++a_it;
	}
	while(left_it != left.end()) {
		*a_it = *left_it;
		++a_it, ++left_it;
	}
	while(right_it != right.end()) {
		*a_it = *right_it;
		++a_it, ++right_it;
	}
}

// templated insertion sort
template <typename T>
void insertion_sort(std::vector<T> &a,int lower_index,int upper_index) {
    T value;
    int index;
    for(int i = lower_index+1; i < upper_index; ++i) {
		int j = i;
		while(a[j] < a[j-1] && j > lower_index) {
			//swap
			T temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			--j;
		}
    }
}

template <typename T>
void bubble_sort(std::vector<T> &a) {
    for(int i = (int)a.size(); i > 0; --i) {
        for(int j=0; j < i; ++j) {
            if(a[j]>a[j+1]) {
                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

template <typename T>
void print_vector(std::vector<T> &a) {
    typename std::vector<T>::iterator it = a.begin();
    while(it != a.end()) {
        std::cout << *it << std::endl;
        it++;
    }
}
