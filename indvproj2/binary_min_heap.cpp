#include "binary_min_heap.h"
#include <iostream>
#include <sstream>
#include <algorithm>

namespace heap {
	// Implemenation class
	class BinaryMinHeap::Impl {
	private:
		std::vector<int> heapVector;
		
		static int objCount;

		// Declare BinaryMinHeap as friend for sharing private methods and variables
		friend class BinaryMinHeap;

		// Helper function to maintain heap property
		void heapify(int pos) {
			int smallest = pos;
			int left = pos * 2 + 1;
			int right = pos * 2 + 2;
			int size = heapVector.size();

			// If left element is smaller then the smallest element change it to be the smallest
			if(left < size && heapVector[left] < heapVector[smallest]){
				smallest = left;
			}

			// If right element is smaller then the smallest element change it to be the smallest
			if(right < size && heapVector[right] < heapVector[smallest]){
				smallest = right;
			}

			// If the smallest element is not the given one then push the given element to the correct position
			if(smallest != pos){
				std::swap(heapVector[pos], heapVector[smallest]);
				heapify(smallest);
			}
		}
	
		// Increase object count
		static void incObjCount() {
			objCount++;
		}

		// Decrease object count
		static void decObjCount() {
			objCount--;
		}
	};

	// Declare static fields
	int BinaryMinHeap::Impl::objCount = 0;

	/* CONSTRUCTORS */

	// Constructor
	BinaryMinHeap::BinaryMinHeap() {
		this->impl = new Impl();
		impl->incObjCount();
	}

	// Copy constructor
	BinaryMinHeap::BinaryMinHeap(const BinaryMinHeap& other) {
		this->impl = new Impl(*other.impl);
	}

	// Equal operator constructor
	BinaryMinHeap& BinaryMinHeap::operator=(const BinaryMinHeap& other) {
		// Check if other is this
		if(this == &other){
			return *this;
		}

		if(this->impl != nullptr) {
			delete this->impl;
			this->impl = nullptr;
		}

		// Assign the implementation from other object to this one
		this->impl = new Impl(*other.impl);

		return *this;
	}

	// Destructor
	BinaryMinHeap::~BinaryMinHeap() {
		if (this->impl != nullptr) {
			delete this->impl;
			this->impl = nullptr; // To avoid double deletion
		}
		impl->decObjCount();
	}

	/* OPERATORS */

	// Exclamation operator to clear the heap
	BinaryMinHeap& BinaryMinHeap::operator!() {
		clear();
		return *this;
	}

	// Bracket operator to access elements on the heap
	int BinaryMinHeap::operator[](int value) {
		return std::count(impl->heapVector.begin(), impl->heapVector.end(), value);
	}

	// Plus equals operator to insert element in to the heap
	BinaryMinHeap& BinaryMinHeap::operator+=(int value){
		insert(value);
		return *this;
	}

	// Minus equals operator to remove element from the heap. Removes the first occurence
	BinaryMinHeap& BinaryMinHeap::operator-=(int value){
		remove(value);
		return *this;
	}

	/* HEAP METHODS */

	// Method to insert an element to the heap
	void BinaryMinHeap::insert(int value) {
		impl->heapVector.push_back(value);
		int pos = impl->heapVector.size() - 1;

		// While position is not root and parent element is bigger than the current element swap
		while(pos != 0 && impl->heapVector[(pos - 1) / 2] > impl->heapVector[pos]) {
			std::swap(impl->heapVector[pos], impl->heapVector[(pos - 1) / 2]);
			pos = (pos - 1) / 2;
		}
	}

	// Method to get and remove the min element from the heap
	int BinaryMinHeap::extractMin() {
		try {
			// Check if heap is not empty
			if (impl->heapVector.size() <= 0) {
				throw HeapException("Heap empty");
			}

			// If only one element return root
			if (impl->heapVector.size() == 1) {
				int root = impl->heapVector[0];
				impl->heapVector.pop_back();
				return root;
			}

			// Get root element
			int root = impl->heapVector[0];

			// Place last element as root
			impl->heapVector[0] = impl->heapVector.back();

			// Remove last element as it is now in the front
			impl->heapVector.pop_back();

			// Reheapify
			impl->heapify(0);

			return root;
		}
		catch(HeapException e){
			std::cout << e.what();
		}
	}

	// Method to get the min element from the heap
	int BinaryMinHeap::getMin() const {
		try {
			if (impl->heapVector.size() <= 0) {
				throw HeapException("Heap empty");
			}
			return impl->heapVector[0];
		}
		catch(HeapException e){
			std::cout << e.what();
		}
	}

	// Method to remove an element by value from the heap. Removes the first occurence
	bool BinaryMinHeap::remove(int value){
		// Find the element
		std::vector<int>::iterator it = std::find(impl->heapVector.begin(), impl->heapVector.end(), value);

		// If element not found return false
		if(it == impl->heapVector.end()){
			return false;
		}

		// Get indexes in the vector
		int valuePosition = std::distance(impl->heapVector.begin(), it);
		int endPosition = impl->heapVector.size() - 1;

		// Swap selected element with last element
		std::swap(impl->heapVector[valuePosition], impl->heapVector[endPosition]);

		// Remove last element
		impl->heapVector.pop_back();

		// Reheapify
		impl->heapify(valuePosition);
	}


	// Method to remove an element by value from the heap. Removes the first occurence
	void BinaryMinHeap::removeAll(int value){
		// Remove all elements till none left
		while(this->remove(value));	
	}

	// Method to clear heap
	void BinaryMinHeap::clear(){
		impl->heapVector.clear();
	}

	// Method to check if heap is empty 
	bool BinaryMinHeap::isEmpty(){
		return impl->heapVector.empty();
	}

	// Returns heap elements in string format
	std::string BinaryMinHeap::toString(){
		// Initialize stringstream object in append mode
		std::stringstream ss("", std::ios_base::in|std::ios_base::out|std::ios_base::ate );

		// Append all elements in order to string
		for(std::vector<int>::iterator it = impl->heapVector.begin(); it != impl->heapVector.end(); it++){
			ss << *it;

			// If not last element add space
			if(impl->heapVector.end() - it != 1){
				ss << " ";
			}
		}

		return ss.str();
	}

	/* OBJECT COUNT FUNCTION */

	// Get object count
	int BinaryMinHeap::getObjCount() {
		return Impl::objCount;
	}
}


