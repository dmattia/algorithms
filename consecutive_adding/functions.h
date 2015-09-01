// functions for main.cpp. program is explained there

#include <iostream>
#include <vector>
#include <algorithm>

struct subarray {
    int lower_index;
    int upper_index;
    double sum;
};

// Assumes class can be added and compared.
// This divide and conquer method takes O(nlogn) time and O(n) space
template <typename T>
struct subarray divide_and_conquer(std::vector<T> &a,int lower_bound,int upper_bound) {
    struct subarray left, right, using_middle;
    
    if(lower_bound == upper_bound) {
        left.lower_index = left.upper_index = lower_bound;
        left.sum = a[lower_bound];
        return left;
    }
    
    int middle_index = (upper_bound+lower_bound)/2;
    
    T sum,maximum_of_left,maximum_of_right;
    sum = maximum_of_left = a[middle_index];
    
    using_middle.lower_index = middle_index;
    using_middle.upper_index = middle_index+1;
    
    for(int i = middle_index-1; i >= 0; --i) {
        sum += a[i];
        if (sum > maximum_of_left) {
            maximum_of_left = sum;
            using_middle.lower_index = i;
        }
    }
    
    sum = maximum_of_right = a[middle_index+1];
    for(int i = middle_index + 2; i <= upper_bound; ++i) {
        sum += a[i];
        if (sum > maximum_of_right) {
            maximum_of_right = sum;
            using_middle.upper_index = i;
        }
    }
    
    left = divide_and_conquer(a, lower_bound, middle_index);
    right = divide_and_conquer(a, middle_index+1, upper_bound);
    using_middle.sum = maximum_of_right+maximum_of_left;
    
    if (left.sum > right.sum && left.sum > using_middle.sum) {
        return left;
    } else if (right.sum > using_middle.sum) {
        return right;
    } else {
        return using_middle;
    }
}

// assumes that a is a non-empty vector
template <typename T>
struct subarray linear_time(std::vector<T> &a) {
    // Start with just the first element.
    // This element is the largest subarray of itself
    // add in an element. Either the current max subarray is
    // still the maximum, otherwise the new max subarray will
    // use the new element. The max subarray using this new value
    // is either the new element alone or the max subarray using
    // the previous element added to the new value.
    
    struct subarray max_subarray;
    max_subarray.lower_index = 0;
    max_subarray.upper_index = 0;
    max_subarray.sum = a[0];
    
    struct subarray max_subarray_using_rightmost_index;
    max_subarray_using_rightmost_index.lower_index = 0;
    max_subarray_using_rightmost_index.upper_index = 0;
    max_subarray_using_rightmost_index.sum = a[0];
    
    int size = (int)a.size();
    for(int i = 1; i < size; ++i) {
        if(max_subarray_using_rightmost_index.sum > 0) {
            max_subarray_using_rightmost_index.upper_index = i;
            max_subarray_using_rightmost_index.sum += a[i];
        } else {
            max_subarray_using_rightmost_index.lower_index = i;
            max_subarray_using_rightmost_index.upper_index = i;
            max_subarray_using_rightmost_index.sum = a[i];
        }
        
        if(max_subarray_using_rightmost_index.sum > max_subarray.sum) {
            max_subarray.lower_index = max_subarray_using_rightmost_index.lower_index;
            max_subarray.upper_index = max_subarray_using_rightmost_index.upper_index;
            max_subarray.sum = max_subarray_using_rightmost_index.sum;
        }
    }
    
    return max_subarray;
}

void print_struct(struct subarray a) {
    std::cout << "lower index: " << a.lower_index << std::endl <<
    "sum: " << a.sum << std::endl <<
    "upper index: " << a.upper_index << std::endl;
}
