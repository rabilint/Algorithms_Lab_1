//
// Created by rabilint on 24.09.25.
//

#include "sort.h"
#include <algorithm>

void countSortByDigit(std::vector<int>& input, int exp, bool reverse )
{
    const int size = input.size();
    std::vector count(10, 0);

    for (int i = 0; i < size; i++)
    {
        count[(input[i] / exp) % 10]++;
    }

    if (reverse)
    {
        for (int i = 8; i >= 0; i--)
        {
            count[i] += count[i + 1];
        }
    }else
    {
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
    }


    std::vector<int> output(size);
    for (int i = size - 1; i >= 0; i--)
    {
        int actualDigit = (input[i] / exp) % 10;
        output[count[actualDigit] - 1] = input[i];
        count[actualDigit]--;
    }
    for (int i = 0; i < size; i++)
    {
        input[i] = output[i];
    }
}

void radixSort(std::vector<int>& array, bool reverse )
{
    if (array.empty()) return;
    int max = *std::max_element(array.begin(), array.end());
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSortByDigit(array, exp, reverse);
    }
}


std::vector<int> countSort(std::vector<int> input, bool reverse)
{
    const int size = input.size();
    int maxval = *std::ranges::max_element(input);
    std::vector countArray(maxval + 1, 0);
    for (int i = 0; i < size; i++)
    {
        countArray[input[i]]++;
    }
    if (!reverse)
    {
        for (int i = 1; i <= maxval; i++)
        {
            countArray[i] += countArray[i - 1];

        }
    }else
    {
        for (int i = maxval - 1; i >= 0; i--)
        {
            countArray[i] += countArray[i + 1];

        }
    }

    std::vector<int> output(size);
    for (int i = size - 1; i >= 0; i--)
    {
        output[countArray[input[i]] - 1] = input[i];
        countArray[input[i]]--;
    }

    return output;
}

