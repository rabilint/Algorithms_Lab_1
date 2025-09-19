#include "sort.h"
#include <iostream>
#include <vector>
#include <limits>

void Merge(std::vector<int>& Array, int left, int mid, int right )
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1 + 1);
    std::vector<int> R(n2 + 1);

    for (int i = 0; i < n1; i++)
    {
        L[i] = Array[left + i];

    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = Array[mid + 1 + j];
    }

    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();

    // int k = left;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++)
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
    }
    // while (i < n1 && j < n2)
    // {
    //     if (L[i] <= R[j])
    //     {
    //         Array[k] = L[i];
    //         i++;
    //     }
    //     else
    //     {
    //         Array[k] = R[j];
    //         j++;
    //     }
    //     k++;
    // }
    // while (i < n1) // Якщо хочемо обійтись без стороживих елементів
    // {
    //     Array[k] = L[i];
    //     i++;
    //     k++;
    // }
    // while (j < n2)
    // {
    //     Array[k] = R[j];
    //     j++;
    //     k++;
    // }
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


