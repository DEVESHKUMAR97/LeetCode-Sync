class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> prev(n, 0), curr(n);
        int prevMin = 0, prevSecondMin = 0;
        int currMin = INT_MAX, currSecondMin = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                curr[j] = grid[i][j] + (prev[j] == prevMin ?  prevSecondMin : prevMin);
                if(curr[j] <= currMin) {
                    currSecondMin = currMin;
                    currMin = curr[j];
                } else if(curr[j] <= currSecondMin) {
                    currSecondMin = curr[j];
                }

            }
            prev = curr;
            prevMin = currMin;
            prevSecondMin = currSecondMin;
            currMin = currSecondMin = INT_MAX;
        }

        return *min_element(curr.begin(), curr.end());
        
    }
};