#include <iostream>
#include "sort.h"
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> arrayToSort = {3,1,7,5,10,8,9,2,4,6};
    std::cout << "Array before sorting:" << std::endl;
    std::copy(arrayToSort.begin(), arrayToSort.end(), std::ostream_iterator<int>(std::cout, " "));
    MergeSort(arrayToSort, 0, arrayToSort.size() - 1);
    std::cout << "\nArray after sotr: " << std::endl;
    std::copy(arrayToSort.begin(), arrayToSort.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
