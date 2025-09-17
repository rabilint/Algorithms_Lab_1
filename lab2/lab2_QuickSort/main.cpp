#include <iostream>
#include <algorithm>
#include <iterator>

#include "QuickSort.h"

int main()
{
    std::vector<int> Array = {2,4,1,9,5,6,7,5,3,7};
    std::cout << "Array before sorting" << std::endl;
    std::copy (Array.begin(), Array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    QuickSort(Array, 0, Array.size() - 1);
    std::cout << "Array after sorting" << std::endl;
    std::copy (Array.begin(), Array.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}