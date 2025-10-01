#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "sort.h"
#include <vector>

int main()
{
    std::string input;
    std::cout << "Insert array to sort like this: \" 9,2,1,3,4,8,7,6,5,9,10 \" :" << std::endl;
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


    std::cout << "Array before sorting: [ ";
    std::copy(arrayToSort.begin(), arrayToSort.end(), std::ostream_iterator<int>(std::cout, " ],[ "));

    std::vector<int> copyArray = countSort(arrayToSort, false);
    std::cout << "\nArray after sort: [ " ;
    std::copy(copyArray.begin(), copyArray.end(), std::ostream_iterator<int>(std::cout, " ],[ "));

    copyArray = countSort(arrayToSort, true);
    std::cout << "\nArray after sorting reverse: [ " ;
    std::copy(copyArray.begin(), copyArray.end(), std::ostream_iterator<int>(std::cout, " ],[ "));

    std::cout << "\n\nsorting by radix";

    copyArray = arrayToSort;
    radixSort(copyArray, false);
    std::cout << "\nArray after sorting: [ " ;
    std::copy(copyArray.begin(), copyArray.end(), std::ostream_iterator<int>(std::cout, " ],[ "));

    std::cout << "\nArray after sorting reverse: [ " ;
    copyArray = arrayToSort;
    radixSort(copyArray, true);
    std::copy(copyArray.begin(), copyArray.end(), std::ostream_iterator<int>(std::cout, " ],[ "));


    return 0;
}