// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    Iterator<Integer> iter;
    Integer peakedValue;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    this.iter = iterator;
        peakedValue = null;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if(peakedValue != null) return peakedValue;
        peakedValue = iter.next();
        return peakedValue;
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
        if(peakedValue != null) {
            Integer ans = peakedValue;
            peakedValue = null;
            return ans;
        }
	    return iter.next();
	}
	
	@Override
	public boolean hasNext() {
        if(peakedValue != null) return true;
	    return iter.hasNext();
	}
}