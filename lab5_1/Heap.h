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

#endif //LAB5_1_HEAP_H