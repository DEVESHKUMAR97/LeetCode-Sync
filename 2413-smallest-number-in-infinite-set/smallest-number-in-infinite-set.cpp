class SmallestInfiniteSet {
    set<int> smallestNumbers;
public:
    SmallestInfiniteSet() {
        smallestNumbers.insert(1);
    }
    
    // O(log(n)) where n : number of addBack operations till now
    int popSmallest() {
        int smallest = *smallestNumbers.begin();
        smallestNumbers.erase(smallest);
        if(smallestNumbers.size() == 0) {
            smallestNumbers.insert(smallest + 1);
        }
        return smallest;
    }
    
    // O(log(n))
    void addBack(int num) {
        int currBiggestStore = *smallestNumbers.rbegin();
        if(num < currBiggestStore) {
            smallestNumbers.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */


 /*


 removed Numbers: 
 1 2 3 4 6 7 8 9 10


smallest
 5 11

 */