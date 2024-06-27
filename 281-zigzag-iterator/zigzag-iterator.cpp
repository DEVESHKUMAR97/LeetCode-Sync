// class ZigzagIterator {
//     int numOfVecs;
//     vector<vector<int>> vecs;
//     int currVector;
//     int totalElements, elementsVisited;
//     vector<int> vecCurrIndex;
// public:
//     ZigzagIterator(vector<int>& v1, vector<int>& v2) {
//         numOfVecs = 2;
//         vecs = vector<vector<int>> (numOfVecs);
//         vecs[0] = v1;
//         vecs[1] = v2;
//         totalElements = v1.size() + v2.size();
//         elementsVisited = 0;
//         currVector = 0;
//         vecCurrIndex = vector<int> (numOfVecs, 0);
//     }

//     int next() {
//         if(hasNext()) {
//             elementsVisited++;
//             while(!(vecCurrIndex[currVector] < vecs[currVector].size())) {
//                 currVector++;
//                 currVector %= numOfVecs;
//             }
//             int ans = vecs[currVector][vecCurrIndex[currVector]];
//             vecCurrIndex[currVector]++;
//             currVector++;
//             currVector %= numOfVecs;
//             return ans;
//         }
//         return -1;
//     }

//     bool hasNext() {
//         return elementsVisited < totalElements;
//     }
// };

class ZigzagIterator {
private:
    queue<pair<vector<int>&, int> > vectorsQueue;
        
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) 
    {
        if(v1.size() > 0) vectorsQueue.push({v1,0});
        if(v2.size() > 0) vectorsQueue.push({v2,0});
    }

    int next() {
        int ans = 0;
        
        pair<vector<int>&, int> current = vectorsQueue.front();
        vectorsQueue.pop();
        vector<int> &v = current.first;
        int index = current.second;
        
        if(index < v.size()) ans = v[index];
        index++;
        if(index < v.size()) vectorsQueue.push({v,index});
        
        return ans; 
    }

    bool hasNext() {
         return !vectorsQueue.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */