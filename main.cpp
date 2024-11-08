#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"
#include <iomanip>
#include "asteroids.h"

using namespace std;

void stabilityTest();

int main() {
    // TODO: Get your vector of custom data type objects ready
    vector<asteroids> asteroid;
    // TODO: loop through vector sizes from 1000 to 100 in decrements of 100
    for (int size = 1000; size >= 100; size -= 100) {
        asteroid.resize(size);
        unsigned long reads, allocations;
        // TODO: sort the vector in four different ways (bubble, ?, heap, ?)
        // Bubble Sort
        vector<asteroids> bubbleAst = asteroid;
        reads = allocations = 0;
        bubbleSort(bubbleAst, reads, allocations);
        cout << "Bubble Sort Size: " << bubbleAst.size() << ", Reads: " << reads << ", allocations: " << allocations << endl;

        // Heap Sort
        vector<asteroids> heapAst = asteroid;
        reads = allocations = 0;
        heapSort(heapAst, reads, allocations);
        cout << "Heap Sort Size: " << heapAst.size() << ", Reads: " << reads << ", allocations: " << allocations << endl;

        vector<asteroids> mergeAst = asteroid;
        reads = allocations = 0;
        mergeSort(mergeAst, reads, allocations);
        cout << "Merge Sort Size: " << mergeAst.size() << ", Reads: " << reads << ", allocations: " << allocations << endl;

        vector<asteroids> quickAst = asteroid;
        reads = allocations = 0;
        quickSortUnstable(quickAst, reads, allocations);
        cout << "Quick Sort Size: " << quickAst.size() << ", Reads: " << reads << ", allocations: " << allocations << endl;

        stabilityTest();
        return 0;
    }
}
void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../stability-test/names.csv");
    cout << "People (Default ordering)" << endl;
    people.printList();

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    // TODO: add other stable algorithm here
    cout << endl << "Merge Sort" << endl;
    people.sortAndPrint(mergeSort<contact>);

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    // TODO: add other unstable algorithm here
    cout << endl << "Quick Sort" << endl;
    people.sortAndPrint(quickSortUnstable<contact>);
}