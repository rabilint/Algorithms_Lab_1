#include <iostream>
#include "Heap.h"
#include <sstream>
#include <algorithm>
#include <iterator>

int main()
{
    std::string input;
    std::cout << "Insert array to sort like this: \" 2,1,3,4,8,7,6,5,9,10 \" :" << std::endl;
    std::vector <int> arrayToSort;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    arrayToSort.reserve(input.size() / 2);
    try
    {
        while (ss.good())
        {
            std::string item;
            std::getline(ss, item, ',');
            arrayToSort.push_back(std::stoi(item));
        }
    }catch (std::invalid_argument& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Relook your input and try to follow the instructions!" << std::endl;
    }

    std::cout << "Array before Heap sort: " ;
    std::ranges::copy(arrayToSort, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector <int> array = arrayToSort;
    HeapSort(array, false);
    std::cout << "Array after Heap sort: " ;
    std::ranges::copy(array, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    array = arrayToSort;
    HeapSort(array, true);
    std::cout << "Array after Heap reverse sort: ";
    std::ranges::copy(array, std::ostream_iterator<int>(std::cout, " "));
    return 0;

}