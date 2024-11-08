#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"

template<typename Comparable>
void quickSortUnstableRec(vector<Comparable> &vec, int startIndex, int endIndex, Comparable& partition, int& i, int& largerElementIndex, Comparable& temp, unsigned long& reads, unsigned long& allocations) {
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Choose a partition element
    partition = vec[startIndex];
    ++reads;

    // Loop through vec from startIndex to endIndex
    // Keep track of where the > partition elements start
    largerElementIndex = startIndex+1;
    for (i = startIndex+1; i <= endIndex; ++i) {
        ++reads;
        ++reads;
        if (vec[i] <= partition) {
            // Swap the smaller/equal item to the left of the larger items
            temp = vec[i];
            ++reads;
            vec[i] = vec[largerElementIndex];
            ++reads;
            vec[largerElementIndex] = temp;
            allocations += 3 * sizeof(Comparable);
            // Update largerElementIndex
            ++largerElementIndex;
        }
    }
    // Swap the partition element into place
    if (startIndex != largerElementIndex-1) {
        temp = vec[startIndex];
        ++reads;
        vec[startIndex] = vec[largerElementIndex - 1];
        ++reads;
        vec[largerElementIndex - 1] = temp;
        allocations += 3 * sizeof(Comparable);
    }

    // Uncomment this line if you want to see each iteration
    //printVec(vec);

    // Recursive calls for two halves
    quickSortUnstableRec(vec, startIndex, largerElementIndex-2, partition, i, largerElementIndex, temp,reads, allocations);
    quickSortUnstableRec(vec, largerElementIndex, endIndex, partition, i, largerElementIndex, temp,reads, allocations);
}

template<typename Comparable>
vector<Comparable> quickSortUnstable(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    Comparable partition, temp;
    int i, largerElementIndex;
    quickSortUnstableRec(vec, 0, vec.size() - 1, partition, i, largerElementIndex, temp, reads, allocations);
    return vec;
}

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec, unsigned long& reads, unsigned long& allocations) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[0];
    ++reads;
    allocations += sizeof(partition);

    vector<Comparable> smaller, equal, larger;
    allocations += sizeof(smaller) + sizeof(equal) + sizeof(larger);
    // Loop through vec and populate smaller, equal, larger
    int i;
    allocations += sizeof(i);

    for (i = 0; i < vec.size(); ++i) {
        ++reads;
        ++reads;

        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
            ++reads;
            allocations += sizeof(Comparable);

        } else if (vec[i] > partition) {
            larger.push_back(vec[i]);
            ++reads;
            allocations += sizeof(Comparable);
        } else {
            equal.push_back(vec[i]);
            ++reads;
            allocations += sizeof(Comparable);
        }
    }

    // Recursive calls
    quickSortStableRec(smaller, reads, allocations);
    quickSortStableRec(larger, reads, allocations);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            ++reads;
            allocations += sizeof(vec[i]);
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            ++reads;
            allocations += sizeof(vec[i]);
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
            ++reads;
            allocations += sizeof(vec[i]);
        }
    }

    // Uncomment this line if you want to see each iteration
    //printVec(vec);
}

template<typename Comparable>
vector<Comparable> quickSortStable(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    quickSortStableRec(vec, reads, allocations);
    return vec;
}

#endif
