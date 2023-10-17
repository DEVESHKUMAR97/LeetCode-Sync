class Solution {
public:
    int findDist(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    vector<vector<int>> dp;
    // time complexity with only bitmasking without dp => O(P(m,c)) ==>  m! / (m-n)! ==> no. of permutations
    // with dp + bit mask => O(m*2^m) => This time complexity is wrong
    // with dp + bit mask => number of state = n * 2^m
    // and transition time for each state = n
    // So total time: O(n^2 * 2^m) and space O(n * 2^m)
    // where n = number of workers and m = number of bikes
    int solve(int workerIndex, int bikesUsed, vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        if(workerIndex == workers.size()) {
            // all workers are assigned a bike
            return 0;
        }
        if(dp[workerIndex][bikesUsed] != -1) return dp[workerIndex][bikesUsed];
        // min total dist for the current recursive call
        int minTotal = INT_MAX;
        for(int i = 0; i < bikes.size(); i++) {
            if((bikesUsed & (1<<i)) == 0) {
                // bike is unused
                int dist = findDist(workers[workerIndex], bikes[i]);
                
                
                int restAns = solve(workerIndex + 1, bikesUsed | (1<<i), workers, bikes);
                
                
                minTotal = min(minTotal, dist + restAns);

            }
        }
        return dp[workerIndex][bikesUsed] = minTotal;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // dp size 
        // rows = number of workers
        // cols = number of various combinations to choose bikes at any steps ==> 0 -> 2^(number of bikes) - 1
        // dp = vector<vector<int>>(n, vector<int>(m, 0))
        int rows = workers.size();
        int cols = pow(2, bikes.size()) - 1;
        dp = vector<vector<int>>(rows, vector<int>(cols, -1));
        int bikesUsed = 0;
        return solve(0, bikesUsed, workers, bikes);
        
    }
};