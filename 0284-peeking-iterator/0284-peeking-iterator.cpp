/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int index=0;
    int size;
    vector<int> numsCopy;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        numsCopy.insert(numsCopy.end(),nums.begin(),nums.end());
        size=nums.size();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return numsCopy[index];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        return numsCopy[index++];
	}
	
	bool hasNext() const {
	    if(index<size) return true;
        return false;
	}
};