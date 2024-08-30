#include<iostream>

void insertionSort(int* arr, int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = arr[j];
        // insert arr[j]
        int i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            // shift elements backward
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

// testing
int main()
{
    // Initial array
    int intArray[]{4, 3, 6, 8, 3, 9, 1, 0, 12, 5};
    std::cout << "Original array: ";
    for (int i: intArray) std::cout << i << " ";
    std::cout << std::endl;

    // sorted array
    int length = sizeof(intArray)/sizeof(int);
    insertionSort(intArray, length);
    std::cout << "Sorted array: ";
    for (int i: intArray) std::cout << i << " ";
    std::cout << std::endl; // 0 1 3 3 4 5 6 8 9 12
}