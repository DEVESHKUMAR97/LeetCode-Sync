class ZigzagIterator {
    int numOfVecs;
    vector<vector<int>> vecs;
    int currVector;
    int totalElements, elementsVisited;
    vector<int> vecCurrIndex;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        numOfVecs = 2;
        vecs = vector<vector<int>> (numOfVecs);
        vecs[0] = v1;
        vecs[1] = v2;
        totalElements = v1.size() + v2.size();
        elementsVisited = 0;
        currVector = 0;
        vecCurrIndex = vector<int> (numOfVecs, 0);
    }

    int next() {
        if(hasNext()) {
            elementsVisited++;
            while(!(vecCurrIndex[currVector] < vecs[currVector].size())) {
                currVector++;
                currVector %= numOfVecs;
            }
            int ans = vecs[currVector][vecCurrIndex[currVector]];
            vecCurrIndex[currVector]++;
            currVector++;
            currVector %= numOfVecs;
            return ans;
        }
        return -1;
    }

    bool hasNext() {
        return elementsVisited < totalElements;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */