//
// Created by rabilint on 19.09.25.
//
#include <random>
#include "QuickSortRand.h"



int Partition(std::vector<int>& Array, int left, int right, bool revers)
{
    int x = Array[right];
    int i = left - 1;
    for (int j = left;  j <= right - 1;  j++ )
    {
        if (revers)
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


int RandomizedPartition(std::vector<int> &array, int low, int high, bool revers)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);

    int i = dis(gen);
    // int i = low + rand() % (high - low + 1);
    std::swap(array[i], array[high]);
    return Partition(array, low, high, revers);
}

int RandomizedSelect(std::vector<int>& array, int low, int high, int i)
{
    bool revers = false;
    if (low == high)
    {
        return array[low];
    }

    int q = RandomizedPartition(array, low, high, revers);
    int k = q - low + 1;
    if (i == k)
    {
        return array[q];
    }
    else if (i < k)
    {
        return  RandomizedSelect(array, low, q - 1, i);
    } else
    {
        return RandomizedSelect(array, q + 1, high, i - k);
    }
}

void RandomizedQuickSort(std::vector<int>& Array, int left, int right, bool revers)
{
    if (left < right)
    {
        int q = RandomizedPartition(Array, left, right, revers);
        RandomizedQuickSort(Array, left, q - 1, revers);
        RandomizedQuickSort(Array, q + 1, right, revers);
    }
}
