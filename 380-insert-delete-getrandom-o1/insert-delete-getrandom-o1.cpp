/**
Approach 1: if no deletion was there then for sure we can use resorvior sampling algorithm.
 I think we can't use resorvior sampling algorithm because we can call getRandom multiple times consecutively and 
 in that we RS algo return the same random number each time.

 go through editorial
 Hashmap provides Insert and Delete in average constant time, although has problems with GetRandom.
 Array List has indexes and could provide Insert and GetRandom in average constant time, though has problems with Delete.

 swapping technique;

*/

class RandomizedSet {
public:
    vector<int> numbers;
    unordered_map<int, int> numIndexes;
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(numIndexes.count(val)) {
            return false;
        }
        numbers.push_back(val);
        numIndexes[val] = numbers.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(numIndexes.count(val)) {
            int indexToDel = numIndexes[val];
            int &numToDel = numbers[indexToDel];
            int &numToSwap = numbers[numbers.size() - 1];
            swap(numToDel, numToSwap);
            numIndexes[numToDel] = indexToDel;
            numbers.pop_back();
            numIndexes.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int numSize = numbers.size();
        return numbers[rand() % numSize];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */