//Library of template functions for working with an array
#ifndef HEADER_H
#define HEADER_H
#include <iostream>

using std::array;

//Template function for swapping elements with specified indexes
template<typename T, size_t N>
void swapElements(array<T, N>& arr, size_t index1, size_t index2) {
	T temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

//Template function for finding an element with a certain value;
template<typename T, size_t N>
int findElement(const array<T, N>& arr, const T& value) {
	for (size_t i = 0; i < N; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}

//Template function for swapping all pairs of neighbouring elements 
template<typename T, size_t N>
void swapNeighbours(array<T, N>& arr) {
	for (size_t i = 0; i < N; i += 2) {
		T temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
}

#endif