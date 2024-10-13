/**
 * PROBLEM: Quick Sort in C++
 * AUTHOR: chaitra-samant
 **/
#include <iostream>
using namespace std;

void quickSort(int*, int, int);
int partition(int*, int, int);

int main() {
    int size;
    
    cout << "Enter the size of the array:\n";
    cin >> size;

    int* array = new int[size];
    
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    quickSort(array, 0, size - 1);
    
    cout << "Sorted array:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

/**
 * This function implements the Quick Sort algorithm
 * 
 * @param array: pointer to the array
 * @param low: starting index of the array to sort
 * @param high: ending index of the array to sort
 **/
void quickSort(int* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high); // Partition

        quickSort(array, low, pi - 1);  // Recursively sort elements before partition
        quickSort(array, pi + 1, high); // Recursively sort elements after partition
    }
}

/**
 * This function partitions the array and places the pivot element at its correct position
 * 
 * @param array: pointer to the array
 * @param low: starting index of the partition
 * @param high: ending index of the partition
 * 
 * @return the index of the pivot element
 **/
int partition(int* array, int low, int high) {
    int pivot = array[high]; // We chose the last element as pivot
    int i = (low - 1);       

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++; 
            swap(array[i], array[j]); // Swap if current element is smaller than pivot
        }
    }
    swap(array[i + 1], array[high]); // Swap the pivot element with the element at index i + 1
    return (i + 1); // Return the partitioning index
}
