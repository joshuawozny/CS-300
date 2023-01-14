#ifndef     _VECTORSORTING_HPP_
# define    _VECTORSORTING_HPP_

/**
* Partition the vector of bids into two parts, low and high
*
* @param bids Address of the vector<Bid> instance to be partitioned
* @param begin Beginning index to partition
* @param end Ending index to partition
*/
int partition(vector<Bid>& bids, int begin, int end) {
	//set low and high equal to begin and end
	int low = begin;
	int high = end;
	// pick the middle element as pivot point
	int midpoint = (begin + end) / 2;
	Bid pivot = bids.at(midpoint);
	// while not done 
	bool done = false;
	while (!done) {
		// keep incrementing low index while bids[low] < bids[pivot]
		while (bids.at(low).title < pivot.title) {
			++low;
		}
		// keep decrementing high index while bids[pivot] < bids[high]
		while (pivot.title < bids.at(high).title) {
			--high;
		}
		/* If there are zero or one elements remaining,
		all bids are partitioned. Return high */
		if (low >= high) {
			done = true;
		}
		else {
			// else swap the low and high bids (built in vector method)
			// move low and high closer ++low, --high
			swap(bids.at(low), bids.at(high));
			++low;
			--high;
		}
	}

	return high;
}

/**
* Perform a selection sort on bid title
* Average performance: O(n^2))
* Worst case performance O(n^2))
*
* @param bid address of the vector<Bid>
*            instance to be sorted
*/
void selectionSort(vector<Bid>& bids) {
	//define min as int (index of the current minimum bid with lowest title)
	int min = 0;
	// check size of bids vector
	// set size_t platform-neutral result equal to bid.size()
	int size_t = bids.size();
	// pos is the position within bids that divides sorted/unsorted
	// for size_t pos = 0 and less than size -1 
	for (unsigned int pos = 0; pos < size_t; ++pos) {
		// set min = pos
		min = pos;
		// loop over remaining elements to the right of position            
		for (unsigned int i = pos + 1; i < size_t; ++i) {
			// if this element's title is less than minimum title
			if (bids.at(i).title.compare(bids.at(min).title) < 0) {
				// this element becomes the minimum
				min = i;
			}
		}
		if (min != pos) {
			// swap the current minimum with smaller one found
			// swap is a built in vector method
			swap(bids.at(pos), bids.at(min));
		}
	}


}

/**
* Perform a quick sort on bid title
* Average performance: O(n log(n))
* Worst case performance O(n^2))
*
* @param bids address of the vector<Bid> instance to be sorted
* @param begin the beginning index to sort on
* @param end the ending index to sort on
*/
void quickSort(vector<Bid>& bids, int begin, int end) {
	//set mid equal to 0
	int mid = 0;
	/* Base case: If there are 1 or zero bids to sort,
	partition is already sorted otherwise if begin is greater
	than or equal to end then return*/
	if (begin >= end) {
		return;
	}
	/* Partition bids into low and high such that
	midpoint is location of last element in low */
	mid = partition(bids, begin, end);
	// recursively sort low partition (begin to mid)
	quickSort(bids, begin, mid);
	// recursively sort high partition (mid+1 to end)
	quickSort(bids, mid + 1, end);

	return;
}



#endif /*!_VECTORSORTING_HPP_*/