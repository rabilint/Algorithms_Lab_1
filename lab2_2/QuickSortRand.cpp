//
// Created by rabilint on 19.09.25.
//
#include <random>
#include "QuickSortRand.h"



int Partition(std::vector<int>& Array, int left, int right)
{
    int x = Array[right];
    int i = left - 1;
    for (int j = left;  j <= right - 1;  j++ )
    {
        if ( Array[j] <= x )
        {
            i = i + 1;
            std::swap(Array[i], Array[j]);
        }
    }
    std::swap(Array[i+1], Array[right]);
    return i + 1;
}


int RandomizedPartition(std::vector<int> &array, int low, int high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);

    int i = dis(gen);
    // int i = low + rand() % (high - low + 1);
    std::swap(array[i], array[high]);
    return Partition(array, low, high);
}

int RandomizedSelect(std::vector<int>& array, int low, int high, int i)
{
    if (low == high)
    {
        return array[low];
    }

    int q = RandomizedPartition(array, low, high);
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
