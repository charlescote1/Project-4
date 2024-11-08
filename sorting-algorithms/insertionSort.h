#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> insertionSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int unsortedStartIndex, insertIndex;
    Comparable toBeInserted;

    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        ++reads;
        allocations += sizeof(toBeInserted);
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        while (insertIndex >= 0 && vec[insertIndex] > toBeInserted) {
            ++reads;
            vec[insertIndex + 1] = vec[insertIndex];
            ++reads;
            ++allocations += sizeof(vec[insertIndex + 1]);
            --insertIndex;
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted;
        ++allocations += sizeof(vec[insertIndex + 1]);

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    return vec;
}

#endif
