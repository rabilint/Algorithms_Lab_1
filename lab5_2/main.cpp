#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Heap.h"

void printArray(const std::string& message, const std::vector<int>& arr) {
    std::cout << message;
    if (arr.empty()) {
        std::cout << "[empty]" << std::endl;
        return;
    }
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main()
{
    std::string input;
    std::cout << "Enter an array of numbers separated by commas, e.g., \"16,4,10,14,7,9,3,2,8,1\"\n: ";
    std::vector<int> originalArray;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    try {
        std::string item;
        while (std::getline(ss, item, ',')) {
            // Trim leading/trailing spaces
            item.erase(0, item.find_first_not_of(" \t\n\r"));
            item.erase(item.find_last_not_of(" \t\n\r") + 1);
            if (!item.empty()) {
                originalArray.push_back(std::stoi(item));
            }
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Input Error: " << e.what() << std::endl;
        return 1;
    }

    if (originalArray.empty()) {
        std::cout << "The array is empty. Exiting." << std::endl;
        return 0;
    }


    std::cout << "\nPART 1: HEAP SORT " << std::endl;
    printArray("Initial array: ", originalArray);

    std::vector<int> arrayForSort = originalArray;
    HeapSort(arrayForSort, false);
    printArray("Array after sort: ", arrayForSort);

    HeapSort(arrayForSort, true);
    printArray("Array after reverse sort: ", arrayForSort);



    std::cout << "\n\n PART 2: PRIORITY QUEUE ";

    std::cout << "\n\n  Max-Heap Demonstration  " << std::endl;
    std::vector<int> maxHeap = originalArray;

    BuildMaxHeap(maxHeap);
    printArray("1. Built Max-Heap: ", maxHeap);

    std::cout << "2. Maximum element (HeapMax): " << HeapMax(maxHeap) << std::endl;

    int extractedMax = HeapExtractMax(maxHeap);
    std::cout << "3. Extracted max (ExtractMax): " << extractedMax << std::endl;
    printArray("   Heap after extraction: ", maxHeap);

    if (maxHeap.size() >= 4) {
        HeapIncreaseKey(maxHeap, 3, 99);
        printArray("4. Increased key A[3] to 99: ", maxHeap);
    }

    MaxHeapInsert(maxHeap, 42);
    printArray("5. Inserted element 42 (Insert): ", maxHeap);

    std::cout << "\nMin-Heap Demonstration " << std::endl;
    std::vector<int> minHeap = originalArray;

    BuildMinHeap(minHeap);
    printArray("1. Built Min-Heap:  ", minHeap);

    std::cout << "2. Minimum element (HeapMin): " << HeapMin(minHeap) << std::endl;

    int extractedMin = HeapExtractMin(minHeap);
    std::cout << "3. Extracted min (ExtractMin): " << extractedMin << std::endl;
    printArray("   Heap after extraction: ", minHeap);

    if (minHeap.size() >= 4) {
        HeapDecreaseKey(minHeap, 3, -5);
        printArray("4. Decreased key A[3] to -5: ", minHeap);
    }

    MinHeapInsert(minHeap, 0);
    printArray("5. Inserted element 0 (Insert): ", minHeap);

    return 0;
}