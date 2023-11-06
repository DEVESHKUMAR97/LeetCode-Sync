// Approach 3: Similar to this problem: https://leetcode.com/problems/smallest-number-in-infinite-set/

class SeatManager {
    set<int> smallestNumbers;
public:
    SeatManager(int n) {
        smallestNumbers.insert(1);
    }
    
    // O(log(n)) where n : number of addBack operations till now
    int reserve() {
        int smallest = *smallestNumbers.begin();
        smallestNumbers.erase(smallest);
        if(smallestNumbers.size() == 0) {
            smallestNumbers.insert(smallest + 1);
        }
        return smallest;
    }
    
    void unreserve(int seatNumber) {
        int currBiggestStore = *smallestNumbers.rbegin();
        if(seatNumber < currBiggestStore) {
            smallestNumbers.insert(seatNumber);
        }
    }
};


// // Approach 2: Using min PQ
// class SeatManager {
//     priority_queue<int, vector<int>, greater<int>> minPQ;
// public:
//     SeatManager(int n) {
//         for(int i = 1; i <= n; i++) minPQ.push(i);
//     }
    
//     int reserve() {
//         if(minPQ.size() > 0) {
//             int seat = minPQ.top(); minPQ.pop();
//             return seat;
//         }
//         return -1;
//     }
    
//     void unreserve(int seatNumber) {
//         minPQ.push(seatNumber);
//     }
// };

// Approach 1: Using Set
// O(log(n)) for each reserve and unreserve operation
// class SeatManager {
//     set<int> availableSeats;
// public:
//     SeatManager(int n) {
//         availableSeats.clear();
//         for(int i = 1; i <= n; i++) availableSeats.insert(i);
//     }
    
//     int reserve() {
//         if(availableSeats.size() > 0) {
//             int seat = *availableSeats.begin();
//             availableSeats.erase(seat);
//             return seat;
//         }
//         return -1;
//     }
    
//     void unreserve(int seatNumber) {
//         availableSeats.insert(seatNumber);
//     }
// };

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */