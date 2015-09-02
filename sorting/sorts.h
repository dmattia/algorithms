//Implementation for sorting

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void improved_merge_sort(std::vector<T> &a) {
    if (a.size() <= 100) {
        insertion_sort(a);
        return;
    }
    
    std::vector<T> left_side(a.begin(),a.begin()+a.size()/2), right_side(a.begin()+a.size()/2,a.end());
    
    improved_merge_sort(left_side);
    improved_merge_sort(right_side);
    
    a = merge_vectors(left_side, right_side);
}

template <typename T>
void merge_sort(std::vector<T> &a) {
    if (a.size()<= 1) return;
    
    std::vector<T> left_side(a.begin(),a.begin()+a.size()/2), right_side(a.begin()+a.size()/2,a.end());

    merge_sort(left_side);
    merge_sort(right_side);
    
    a = merge_vectors(left_side, right_side);
}

// Precondition: vectors a and b are sorted
// Postcondition: a sorted vector is returned with all values from a and b
template <typename T>
std::vector<T> merge_vectors(std::vector<T> &a, std::vector<T> &b) {
    std::vector<T> merged;
    int a_index = 0, b_index = 0;
    while(a_index < a.size() && b_index < b.size()) {
        if(a[a_index] <= b[b_index]) {
            merged.push_back(a[a_index]);
            a_index++;
        } else {
            merged.push_back(b[b_index]);
            b_index++;
        }
    }
    while(b_index < b.size()) {
        merged.push_back(b[b_index]);
        b_index++;
    }
    while(a_index < a.size()) {
        merged.push_back(a[a_index]);
        a_index++;
    }
    return merged;
}

// templated insertion sort
template <typename T>
void insertion_sort(std::vector<T> &a) {
    T value;
    int index;
    for(int i = 1; i < a.size(); ++i) {
		int j = i;
		while(a[j] < a[j-1] && j > 0) {
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
