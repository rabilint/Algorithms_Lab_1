//
// Created by rabilint on 05.10.25.
//

#include "Heap.h"
#include <iostream>
#include <limits>

int Parent(int index) {
    return (index - 1) / 2;
}

int Left(int index) {
    return 2 * index + 1;
}

int Right(int index) {
    return 2 * index + 2;
}


void MaxHeap(std::vector<int>& Array, int index, int n)
{
    int left = Left(index);
    int right = Right(index);
    int largest = index;

    if (left < n && Array[left] > Array[largest])
    {
        largest = left;
    }
    if (right < n && Array[right] > Array[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        std::swap(Array[index], Array[largest]);
        MaxHeap(Array, largest, n);
    }
}

void BuildMaxHeap(std::vector<int>& Array)
{
    int n = Array.size();
    int last_parent = ((n - 1 - 1) / 2);
    for (int i = last_parent; i >= 0; i--)
    {
        MaxHeap(Array, i, n);
    }
}

void MinHeap(std::vector<int>& Array, int index, int n)
{
    int left = Left(index);
    int right = Right(index);
    int smallest = index;
    if (left < n && Array[left] < Array[smallest])
    {
        smallest = left;
    }
    if (right < n && Array[right] < Array[smallest])
    {
        smallest = right;
    }

    if (smallest != index)
    {
        std::swap(Array[index], Array[smallest]);
        MinHeap(Array, smallest, n);
    }
}

void BuildMinHeap(std::vector<int>& Array)
{
    int n = Array.size();
    int last_parent = ((n - 1 - 1) / 2);
    for (int i = last_parent; i >= 0; i--)
    {
        MinHeap(Array, i, n);
    }
}

void HeapSort(std::vector<int>& Array, bool reverse)
{
    if (Array.size() <=1)
    {
        return;
    }
    int n = Array.size();
    if (reverse)
    {
        BuildMinHeap(Array);
    }else
    {
        BuildMaxHeap(Array);
    }

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(Array[0], Array[i]);
        if (reverse)
        {
            MinHeap(Array, 0, i);
        }else
        {
            MaxHeap(Array, 0, i);
        }

    }
}

int HeapMax(std::vector<int>& heap)
{
    if (heap.empty()) {
        std::cerr << "Error: Heap is empty!" << std::endl;
        return -1;
    }
    return heap[0];
}

int HeapMin(std::vector<int>& heap)
{
    if (heap.empty()) {
        std::cerr << "Error: Heap is empty!" << std::endl;
        return -1;
    }
    return heap[0];
}

int HeapExtractMax(std::vector<int>& array)
{
    int tmp = array[0];
    std::swap(array[0], array.back());
    array.pop_back();
    MaxHeap(array, 0, array.size() );
    return tmp;
}
int HeapExtractMin(std::vector<int>& array)
{
    if (array.empty())
    {
        std::cerr << "Error: Heap is empty!" << std::endl;
    }
    int tmp = array[0];
    std::swap(array[0], array.back());
    array.pop_back();
    if (!array.empty())
    {
        MinHeap(array, 0, array.size());
    }
    return tmp;
}


void HeapIncreaseKey(std::vector<int>& array, int index, int key)
{
    if (key < array[index])
    {
        std::cout << "Key: " << key << " is lower than: " << array[index] << std::endl;
    }

    array[index] = key;
    while (array[index] != array[0] && array[index] > array[Parent(index)])
    {
        std::swap(array[index], array[Parent(index)]);
        index = Parent(index);
    }
}

void HeapDecreaseKey(std::vector<int>& array, int index, int key)
{
    if (key > array[index])
    {
        std::cout << "Key: " << key << " is greater than: " << array[index] << std::endl;
        return;
    }

    array[index] = key;
    while (array[index] != array[0] && array[index] < array[Parent(index)])
    {
        std::swap(array[index], array[Parent(index)]);
        index = Parent(index);
    }
}

void MaxHeapInsert(std::vector<int>& array, int key)
{
    array.push_back(std::numeric_limits<int>::min());
    HeapIncreaseKey(array, array.size() - 1, key);
}

void MinHeapInsert(std::vector<int>& array, int key)
{
    array.push_back(std::numeric_limits<int>::max());
    HeapDecreaseKey(array, array.size() - 1, key);
}
