#include <iostream>
#include "QuickSortRand.h"
#include <algorithm>
#include <iterator>
#include <sstream>

int main()
{
    std::string input;
    std::cout << "Insert array to sort like this: \" 2,1,3,4,8,7,6,5,9,10 \" :" << std::endl;
    std::vector <int> Array;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    Array.reserve(input.size() / 2);
    try
    {
        while (ss.good())
        {
            std::string item;
            std::getline(ss, item, ',');
            Array.push_back(std::stoi(item));
        }
    }catch (std::invalid_argument& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Relook your input and try to follow the instructions!" << std::endl;
    }

    int n = Array.size();
    std::cout << "Original Array : ";
    std::copy(Array.begin(), Array.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
    std::cout << "Sorted Array by randomized QuickSort: ";
    RandomizedQuickSort(Array, 0, n - 1, false);
    std::copy(Array.begin(), Array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout <<"\nSorted Array reverse: ";
    RandomizedQuickSort(Array, 0, n - 1, true);
    std::copy(Array.begin(), Array.end(), std::ostream_iterator<int>(std::cout, " "));

    if (n > 0)
    {
        int min_val = RandomizedSelect(Array, 0, n - 1, 1);
        std::cout << "\nMinimal value: " << min_val << std::endl;

        int max_val = RandomizedSelect(Array, 0, n - 1, n);
        std::cout << "Maximal value: " << max_val << std::endl;

        int median = RandomizedSelect(Array, 0, n - 1, (n + 1) /2);
        std::cout << "Median value: " << median << std::endl;

        if (n >= 3) {
            int i = 3;
            int ith_val = RandomizedSelect(Array, 0, n - 1, i);
            std::cout << i << "-rd statistic: " << ith_val << std::endl;
        }
    }
    return 0;
}