//
// Created by rabilint on 17.09.25.
//

#include "QuickSort.h"

int Partition(std::vector<int>& Array, int left, int right, bool reverse)
{
    int x = Array[right];
    int i = left - 1;
    for (int j = left;  j <= right - 1;  j++ )
    {
        if (reverse)
        {
            if ( Array[j] >= x )
            {
                i = i + 1;
                std::swap(Array[i], Array[j]);
            }
        }else
        {
            if ( Array[j] <= x )
            {
                i = i + 1;
                std::swap(Array[i], Array[j]);
            }
        }
    }
    std::swap(Array[i+1], Array[right]);
    return i + 1;
}

void QuickSort(std::vector<int>& Array, int left, int right, bool reverse)
{
    if (left < right)
    {
        int q = Partition(Array, left, right, reverse);
        QuickSort(Array, left, q - 1, reverse);
        QuickSort(Array, q + 1, right, reverse);
    }
}
