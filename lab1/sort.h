#ifndef SORT_H
#define SORT_H
#include <vector>

typedef int datatype;

int SortBubble(datatype arr[], int n, unsigned int iteration, short reverseBinary, int start, int end);

int SortInsertion(datatype arr[], int n, unsigned int &iteration, bool reverseBinary, int start, int end) ;

int SortSelection(datatype arr[], int n, unsigned int &iteration, bool reverseBinary, int start, int end);

void MergeSort(std::vector<int>& Array, int left, int right);


void show(datatype arr[], int n, int unsigned iteration);
int MinItem(datatype arr[], int start, int end);
int MaxItem(datatype arr[], int start, int end);


#endif

