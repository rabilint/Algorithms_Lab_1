//
// Created by rabilint on 05.10.25.
//

#include "Heap.h"

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