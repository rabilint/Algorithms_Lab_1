#include "sort.h"
#include <iostream>
#include <vector>

template <typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

void Merge(std::vector<int>& Array, int left, int mid, int right )
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1 + 1);
    std::vector<int> R(n2 + 1);
    for (int i = 0; i < n1 + 1; i++)
    {
        L[i] = Array[left + i];

    }
    for (int i = 0; i < n2 + 1; i++)
    {
        R[i] = Array[mid + 1 + i];
    }
    int k = left;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            Array[k] = L[i];
            i++;
        }
        else
        {
            Array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        Array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        Array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int>& Array, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    MergeSort(Array, left, mid);
    MergeSort(Array, mid + 1, right);
    Merge(Array, left, mid, right);
}

void show(datatype arr[], int n, int unsigned iteration) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Кількість ітерацій: " << iteration<<std::endl;

}

int MinItem(datatype arr[], int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
int MaxItem(datatype arr[], int start, int end) {
    int maxIndex = end;
    for (int i = end; i >= start; i--) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}



int SortBubble(datatype arr[], int n, unsigned int iteration, short reverseBinary, int start, int end) {
    iteration =0;
    if (end == -1) {
        end = n - 1;
    }
    if (start < 0 || start >= n || end < 0 || end >= n || start >= end) {
        return iteration;
    }

    for (int i = start; i < end; ++i) {
        for (int j = end; j > i; --j) {
            iteration++;
            if (reverseBinary == 1) {
                if (arr[j] > arr[j - 1]) {
                    swap(&arr[j - 1], &arr[j]);
                }
            } else {
                if (arr[j] < arr[j - 1]) {
                    swap(&arr[j], &arr[j - 1]);
                }
            }
        }
    }

    // show(arr, n, iteration);
    return iteration;
}


int SortInsertion(datatype arr[], int n, unsigned int &iteration, bool reverseBinary, int start, int end) {
    if (end == -1) end = n - 1;
    iteration = 0;

    for (int i = start + 1; i <= end; i++) {
        datatype insertingElement = arr[i];
        int location = i - 1;

        while (location >= start && ((reverseBinary && arr[location] < insertingElement) ||
                                     (!reverseBinary && arr[location] > insertingElement))) {
            arr[location + 1] = arr[location];
            iteration++;
            location--;
                                     }
        arr[location + 1] = insertingElement;
    }
    return iteration;
}


int SortSelection(datatype arr[], int n, unsigned int &iteration, bool reverseBinary, int start, int end) {
    if (end == -1) end = n - 1;
    iteration = 0;

    for (int i = start; i < end; i++) {
        int chosenIndex = reverseBinary ? MaxItem(arr, i, end) : MinItem(arr, i, end);
        swap(&arr[i], &arr[chosenIndex]);
        iteration++;
    }
    return iteration;
}