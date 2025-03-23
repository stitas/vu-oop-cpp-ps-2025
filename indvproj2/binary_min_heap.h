#ifndef BINARY_MIN_HEAP_H
#define BINARY_MIN_HEAP_H

#include <vector>
#include <string>

namespace heap {
	class BinaryMinHeap {
	private:
		class Impl;
		Impl* impl;

		static int objCount;

		static void incObjCount();
		static void decObjCount();
	public:
		// friend class Impl;

		// Constructor and destrucor
		BinaryMinHeap();
		~BinaryMinHeap();

		// Copy constructor
		BinaryMinHeap(const BinaryMinHeap& other);

		// Equal operator constructor
		BinaryMinHeap& operator=(const BinaryMinHeap& other);

		// Exclamation operator to clear the heap
		BinaryMinHeap& operator!();

		// Plus equals operator to insert element in to the heap
		BinaryMinHeap& operator+=(int value);

		// Method to insert an element to the heap
		void insert(int value);

		// Method to get and remove the min element from the heap
		int extractMin();

		// Method to get the min element from the heap
		int getMin() const;

		// Method to remove an element at given position from the heap
		void remove(int pos);

		// Method to update an element with a given value at a given position in the heap
		void update(int pos, int value);

		// Method to clear heap
		void clear();

		// Method to check if heap is empty 
		bool isEmpty();

		// Returns heap elements in string format
		std::string toString();

		// Static method to get the created object count
		static int getObjCount();
	};
}

#endif