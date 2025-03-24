#include "binary_min_heap.h"
#include <iostream>
#include <assert.h>
#include <string.h>

int main() {
	// Test heap creation
	std::cout << "TEST HEAP CREATION\n\n";

	// Test 1
	heap::BinaryMinHeap* bmh1 = new heap::BinaryMinHeap();
	std::cout << "heap::BinaryMinHeap* bmh1 = new heap::BinaryMinHeap();\n";

	std::cout << "EXPECTED: 1\n";
	std::cout << "RESULT: ";
	std::cout << heap::BinaryMinHeap::getObjCount() << "\n";
	assert(heap::BinaryMinHeap::getObjCount() == 1);
	std::cout << "PASSED!\n\n";

	// Test 2
	heap::BinaryMinHeap* bmh2 = new heap::BinaryMinHeap(*bmh1);
	std::cout << "heap::BinaryMinHeap* bmh2 = new heap::BinaryMinHeap(*bmh1);\n";

	std::cout << "EXPECTED: 2\n";
	std::cout << "RESULT: ";
	std::cout << heap::BinaryMinHeap::getObjCount() << "\n";
	assert(heap::BinaryMinHeap::getObjCount() == 2);
	std::cout << "PASSED!\n\n";

	// Test 3
	heap::BinaryMinHeap bmh3;
	bmh3 = *bmh2;
	std::cout << "heap::BinaryMinHeap bmh3 = *bmh2;\n";

	std::cout << "EXPECTED: 3\n";
	std::cout << "RESULT: ";
	std::cout << heap::BinaryMinHeap::getObjCount() << "\n";
	assert(heap::BinaryMinHeap::getObjCount() == 3);
	std::cout << "PASSED!\n\n";

	// Test Insertion
	std::cout << "TEST ELEMENT INSERTION\n\n";

	// Test 1
	bmh1->insert(5);
	std::cout << "bmh1->insert(5);\n";

	std::cout << "EXPECTED: 5\n";
	std::cout << "RESULT: ";
	std::cout << bmh1->toString() << "\n";
	assert(strcmp(bmh1->toString().c_str(), "5") == 0);
	std::cout << "PASSED!\n\n";

	// Test 2
	bmh1->insert(4);
	bmh1->insert(1);
	bmh1->insert(6);
	std::cout << "bmh1->insert(4);\n";
	std::cout << "bmh1->insert(1);\n";
	std::cout << "bmh1->insert(6);\n";

	std::cout << "EXPECTED: 1 5 4 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh1->toString() << "\n";
	assert(strcmp(bmh1->toString().c_str(), "1 5 4 6") == 0);
	std::cout << "PASSED!\n\n";

	// Test 3
	*bmh2 += 4;
	*bmh2 += 1;
	*bmh2 += 6;
	std::cout << "*bmh2 += 4;\n";
	std::cout << "*bmh2 += 1;\n";
	std::cout << "*bmh2 += 6;\n";

	std::cout << "EXPECTED: 1 4 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->toString() << "\n";
	assert(strcmp(bmh2->toString().c_str(), "1 4 6") == 0);
	std::cout << "PASSED!\n\n";

	// Test extract min
	std::cout << "TEST MIN ELEMENT EXTRACTION\n\n";

	int min = bmh1->extractMin();
	std::cout << "int min = bmh1->extractMin();\n";

	// Test 1
	std::cout << "EXPECTED: 1\n";
	std::cout << "RESULT: ";
	std::cout << min << "\n";
	assert(min == 1);
	std::cout << "PASSED!\n\n";

	std::cout << "EXPECTED: 4 5 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh1->toString() << "\n";
	assert(strcmp(bmh1->toString().c_str(), "4 5 6") == 0);
	std::cout << "PASSED!\n\n";

	// Test 2
	min = bmh1->extractMin();
	std::cout << "int min = bmh1->extractMin();\n";

	std::cout << "EXPECTED: 4\n";
	std::cout << "RESULT: ";
	std::cout << min << "\n";
	assert(min == 4);
	std::cout << "PASSED!\n\n";

	std::cout << "EXPECTED: 5 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh1->toString() << "\n";
	assert(strcmp(bmh1->toString().c_str(), "5 6") == 0);
	std::cout << "PASSED!\n\n";

	// Test get min
	std::cout << "TEST GET MIN ELEMENT\n\n";

	// Test 1
	min = bmh1->getMin();
	std::cout << "int min = bmh1->getMin();\n";

	std::cout << "EXPECTED: 5\n";
	std::cout << "RESULT: ";
	std::cout << min << "\n";
	assert(min == 5);
	std::cout << "PASSED!\n\n";

	std::cout << "EXPECTED: 5 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh1->toString() << "\n";
	assert(strcmp(bmh1->toString().c_str(), "5 6") == 0);
	std::cout << "PASSED!\n\n";

	// Test remove
	std::cout << "TEST REMOVE ELEMENT\n\n";

	// Test 1
	bmh2->remove(0);
	std::cout << "bmh2->remove(0);\n";
	std::cout << "EXPECTED: 1 4 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->toString() << "\n";
	assert(strcmp(bmh2->toString().c_str(), "1 4 6") == 0);
	std::cout << "PASSED!\n\n";

	// Test 2
	bmh2->remove(4);
	std::cout << "bmh2->remove(4);\n";
	std::cout << "EXPECTED: 1 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->toString() << "\n";
	assert(strcmp(bmh2->toString().c_str(), "1 6") == 0);
	std::cout << "PASSED!\n\n";

	// Test 3
	bmh2->insert(4);
	bmh2->insert(4);
	bmh2->insert(4);
	std::cout << "bmh2->insert(4);\n";
	std::cout << "bmh2->insert(4);\n";
	std::cout << "bmh2->insert(4);\n";
	std::cout << "EXPECTED: 1 4 4 6 4\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->toString() << "\n";
	assert(strcmp(bmh2->toString().c_str(), "1 4 4 6 4") == 0);
	std::cout << "PASSED!\n\n";


	bmh2->removeAll(4);
	std::cout << "bmh2->removeAll(4);\n";
	std::cout << "EXPECTED: 1 6\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->toString() << "\n";
	assert(strcmp(bmh2->toString().c_str(), "1 6") == 0);
	std::cout << "PASSED!\n\n";


	// Test 4
	*bmh2 -= 6;
	std::cout << "bmh2 -= 6;\n";
	std::cout << "EXPECTED: 1\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->toString() << "\n";
	assert(strcmp(bmh2->toString().c_str(), "1") == 0);
	std::cout << "PASSED!\n\n";

	// Test element count
	std::cout << "TEST ELEMENT COUNT\n\n";

	// Test 1

	bmh2->insert(4);
	bmh2->insert(4);
	bmh2->insert(4);
	std::cout << "bmh2->insert(4);\n";
	std::cout << "bmh2->insert(4);\n";
	std::cout << "bmh2->insert(4);\n";
	std::cout << "EXPECTED: 1 4 4 4\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->toString() << "\n";
	assert(strcmp(bmh2->toString().c_str(), "1 4 4 4") == 0);
	std::cout << "PASSED!\n\n";

	int fourCount = (*bmh2)[4];
	std::cout << "(*bmh2)[4];\n";

	std::cout << "EXPECTED: 3\n";
	std::cout << "RESULT: ";
	std::cout << fourCount << "\n";
	assert(fourCount == 3);
	std::cout << "PASSED!\n\n";

	// Test clear heap
	std::cout << "TEST CLEAR HEAP\n\n";

	// Test 1
	bmh1->clear();
	std::cout << "bmh1->clear()\n";
	std::cout << "EXPECTED: 1 (isEmpty)\n";
	std::cout << "RESULT: ";
	std::cout << bmh1->isEmpty() << "\n";
	assert(bmh1->isEmpty() == true);
	std::cout << "PASSED!\n\n";

	// Test 1
	!(*bmh2);
	std::cout << "!(*bmh2)\n";
	std::cout << "EXPECTED: 1 (isEmpty)\n";
	std::cout << "RESULT: ";
	std::cout << bmh2->isEmpty() << "\n";
	assert(bmh2->isEmpty() == true);
	std::cout << "PASSED!\n\n";
	
	// Test delete
	std::cout << "TEST DELETE HEAP\n\n";

	// Test 1
	delete bmh1;
	std::cout << "delete bmh1;\n";
	std::cout << "EXPECTED: 2 (object count)\n";
	std::cout << "RESULT: ";
	std::cout << heap::BinaryMinHeap::getObjCount() << "\n";
	assert(heap::BinaryMinHeap::getObjCount() == 2);
	std::cout << "PASSED!\n\n";

	// Test 1
	delete bmh2;
	std::cout << "delete bmh2;\n";
	std::cout << "EXPECTED: 1 (object count)\n";
	std::cout << "RESULT: ";
	std::cout << heap::BinaryMinHeap::getObjCount() << "\n";
	assert(heap::BinaryMinHeap::getObjCount() == 1);
	std::cout << "PASSED!\n\n";

	std::cout << "ALL TEST CASES PASSED !\n";

	return 0;
}