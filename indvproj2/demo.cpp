#include "binary_min_heap.h"
#include <iostream>

int main() {
	// Create heap via default constructor
	heap::BinaryMinHeap* bmh1 = new heap::BinaryMinHeap();
	
	// Create heap via copy constructor
	heap::BinaryMinHeap* bmh2 = new heap::BinaryMinHeap(*bmh1);

	// Create heap equal sign constructor
	heap::BinaryMinHeap bmh3;
	bmh3 = *bmh2;

	// Insert value to the heap
	bmh1->insert(9);
	bmh1->insert(8);
	bmh1->insert(7);
	bmh1->insert(6);
	bmh1->insert(5);

	// Insert value to the heap
	*bmh2 += 1;
	*bmh2 += 2;
	*bmh2 += 3;
	*bmh2 += 4;

	// Insert value to the heap
	bmh3 += 100;
	bmh3 += 200;
	bmh3.insert(300);
	bmh3.insert(400);

	// Get the min value and remove from heap
	int extractedMin = bmh1->extractMin();

	// Get the min value (value does not get removed)
	int gottenMin = bmh1->getMin();

	// Remove element from heap at position 2. Positions range from 0
	bmh1->remove(2);

	// Update element with given value at given position. Positions range from 0
	bmh1->update(1, 31);

	// Clear the heap.
	bmh1->clear();
	
	// Clear the heap
	!(*bmh2);

	// Check if heap is empty
	bmh1->isEmpty();
	bmh2->isEmpty();

	// Get current object count
	heap::BinaryMinHeap::getObjCount();

	delete bmh1;
	delete bmh2;

	return 0;
}