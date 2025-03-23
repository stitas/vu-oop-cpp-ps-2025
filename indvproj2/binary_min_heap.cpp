#include "binary_min_heap.h"
#include <iostream>
#include <sstream>

namespace heap {
	// Declare static fields
	int BinaryMinHeap::objCount = 0;

	// Implemenation class
	class BinaryMinHeap::Impl {
	private:
		std::vector<int> heapVector;

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

	public:
		Impl() {}

		// Copy constructor
		Impl(const Impl& other) {
			setHeapVector(other.getHeapVector());
		}

		// Heap vector setter
		void setHeapVector(const std::vector<int>& heapVector) {
			this->heapVector = heapVector;
		}

		// Heap vector getter
		std::vector<int> getHeapVector() const {
			return this->heapVector;
		}

		std::string toString() {
			// Initialize stringstream object in append mode
			std::stringstream ss("", std::ios_base::in|std::ios_base::out|std::ios_base::ate );

			// Append all elements in order to string
			for(std::vector<int>::iterator it = heapVector.begin(); it != heapVector.end(); it++){
				ss << *it;

				// If not last element add space
				if(heapVector.end() - it != 1){
					ss << " ";
				}
			}

			return ss.str();
		}

		// Heap methods

		// Method to insert an element to the heap
		void insert(int value){
			heapVector.push_back(value);
			int pos = heapVector.size() - 1;

			// While position is not root and parent element is bigger than the current element swap
			while(pos != 0 && heapVector[(pos - 1) / 2] > heapVector[pos]) {
				std::swap(heapVector[pos], heapVector[(pos - 1) / 2]);
				pos = (pos - 1) / 2;
			}
		}
		
		// Method to get and remove the min element from the heap
		int extractMin() {
			try {
				// Check if heap is not empty
				if (heapVector.size() <= 0) {
					throw HeapException("Heap empty");
				}
	
				// If only one element return root
				if (heapVector.size() == 1) {
					int root = heapVector[0];
					heapVector.pop_back();
					return root;
				}
	
				// Get root element
				int root = heapVector[0];

				// Place last element as root
				heapVector[0] = heapVector.back();

				// Remove last element as it is now in the front
				heapVector.pop_back();

				// Reheapify
				heapify(0);

				return root;
			}
			catch(HeapException e){
				std::cout << e.what();
			}
		}

		// Method to get the max element from the heap
		int getMin() const {
			try {
				if (heapVector.size() <= 0) {
					throw HeapException("Heap empty");
				}
				return heapVector[0];
			}
			catch(HeapException e){
				std::cout << e.what();
			}
		}

		// Method to remove an element at given position from the heap
		void remove(int pos){
			try {
				if (pos >= heapVector.size()) {
					throw HeapException("Position out of bounds");
				}
			
				// Place the last element instead of removed element
				heapVector[pos] = heapVector.back();

				// Remove the last element
				heapVector.pop_back();

				// Reheapify
				heapify(pos);
			}
			catch(HeapException e){
				std::cout << e.what();
			}
		}

		// Method to update an element with a given value at a given position in the heap
		void update(int pos, int value){
			try {
				if (pos >= heapVector.size()) {
					throw HeapException("Position out of bounds");
				}
			
				heapVector[pos] = value;
				while (pos != 0 && heapVector[(pos - 1) / 2] > heapVector[pos]) {
					std::swap(heapVector[pos], heapVector[(pos - 1) / 2]);
					pos = (pos - 1) / 2;
				}
			}
			catch(HeapException e){
				std::cout << e.what();
			}
			
		}

		// Method to clear heap
		void clear() {
			heapVector.clear();
		}
		
		// Method to check whether the heap is empty
		bool isEmpty() {
			return heapVector.empty();
		}
	};

	// Constructor
	BinaryMinHeap::BinaryMinHeap() {
		this->impl = new Impl();
		incObjCount();
	}

	// Copy constructor
	BinaryMinHeap::BinaryMinHeap(const BinaryMinHeap& other) {
		this->impl = new Impl(*other.impl);
		incObjCount();
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
		decObjCount();
	}

	// Exclamation operator to clear the heap
	BinaryMinHeap& BinaryMinHeap::operator!() {
		this->impl->clear();
		return *this;
	}

	// Plus equals operator to insert element in to the heap
	BinaryMinHeap& BinaryMinHeap::operator+=(int value){
		this->impl->insert(value);
		return *this;
	}

	// Increase object count
	void BinaryMinHeap::incObjCount() {
		objCount++;
	}

	// Decrease object count
	void BinaryMinHeap::decObjCount() {
		objCount--;
	}

	// Get object count
	int BinaryMinHeap::getObjCount() {
		return objCount;
	}

	// Method to insert an element to the heap
	void BinaryMinHeap::insert(int value) {
		this->impl->insert(value);
	}

	// Method to get and remove the min element from the heap
	int BinaryMinHeap::extractMin() {
		return this->impl->extractMin();
	}

	// Method to get the min element from the heap
	int BinaryMinHeap::getMin() const {
		return this->impl->getMin();
	}

	// Method to remove an element at given position from the heap
	void BinaryMinHeap::remove(int pos){
		this->impl->remove(pos);
	}

	// Method to update an element with a given value at a given position in the heap
	void BinaryMinHeap::update(int pos, int value){
		this->impl->update(pos, value);
	}

	// Method to clear heap
	void BinaryMinHeap::clear(){
		this->impl->clear();
	}

	// Method to check if heap is empty 
	bool BinaryMinHeap::isEmpty(){
		this->impl->isEmpty();
	}

	// Returns heap elements in string format
	std::string BinaryMinHeap::toString(){
		return this->impl->toString();
	}
}


