#ifndef BINARY_MIN_HEAP_H
#define BINARY_MIN_HEAP_H

#include <vector>
#include <string>

namespace heap {
	class BinaryMinHeap {
	private:
		class Impl;
		Impl* impl;

	public:
		/* CONSTRUCTORS */
		BinaryMinHeap();

		// Copy constructor
		BinaryMinHeap(const BinaryMinHeap& other);

		// Equal operator constructor
		BinaryMinHeap& operator=(const BinaryMinHeap& other);

		// Destructor
		~BinaryMinHeap();

		/* OPERATORS */

		// Exclamation operator to clear the heap
		BinaryMinHeap& operator!();

		// Bracket operator to get element count on the heap
		int operator[](int value);

		// Plus equals operator to insert element in to the heap
		BinaryMinHeap& operator+=(int value);

		// Minus equals operator to remove element from the heap. Removes the first occurence
		BinaryMinHeap& operator-=(int value);

		/* HEAP METHODS */

		// Method to insert an element to the heap
		void insert(int value);

		// Method to get and remove the min element from the heap
		int extractMin();

		// Method to get the min element from the heap
		int getMin() const;

		// Method to remove an element by value from the heap. Removes the first occurence
		bool remove(int value);

		// Method to remove all elements by value from the heap
		void removeAll(int value);

		// Method to clear heap
		void clear();

		// Method to check if heap is empty 
		bool isEmpty();

		// Returns heap elements in string format
		std::string toString();
		
		/* OBJECT COUNT FUNCTION */

		// Static method to get the created object count
		static int getObjCount();

		/* EXCEPTION CLASS*/

		// Custom exception class
		class HeapException : public std::exception {
		private:
			std::string message;
	
		public:
			HeapException(const std::string& msg) : message(msg) {}
	
			const char* what() const noexcept override {
				return message.c_str();
			}
		};
	};
}

#endif