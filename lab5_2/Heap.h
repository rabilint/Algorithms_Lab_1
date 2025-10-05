//
// Created by rabilint on 05.10.25.
//

#ifndef LAB5_1_HEAP_H
#define LAB5_1_HEAP_H
#include <vector>

int Left( int index);
int Right( int index);
int Parent( int index);

void MaxHeap(std::vector<int>& Array, int index, int n);
void BuildMaxHeap(std::vector<int>& Array);

void MinHeap(std::vector<int>& Array, int index, int n);
void BuildMinHeap(std::vector<int>& Array);

void HeapSort(std::vector<int>& Array, bool reverse);



int HeapMax(std::vector<int>& heap);
int HeapMin(std::vector<int>& heap);

int HeapExtractMax(std::vector<int>& array);
int HeapExtractMin(std::vector<int>& array);

void HeapIncreaseKey(std::vector<int>& array, int index, int key);
void HeapDecreaseKey(std::vector<int>& array, int index, int key);

void MaxHeapInsert(std::vector<int>& array, int key);
void MinHeapInsert(std::vector<int>& array, int key);



#endif //LAB5_1_HEAP_H