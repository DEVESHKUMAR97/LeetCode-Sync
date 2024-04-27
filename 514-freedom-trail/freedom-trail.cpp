class Solution {
    vector<vector<int>> dp;
    int totalDistance(int currPos, int idx, string& key, int n, vector<vector<int>>& clockWiseDistance, vector<vector<int>>& antiClockWiseDistance) {
        if(idx == key.length()) return 0;

        int& ans = dp[currPos][idx];
        if(ans != -1) return ans;

        // move clockWise
        int nextPos = (currPos + clockWiseDistance[currPos][key[idx]-'a']) % n;
        int ans1 = clockWiseDistance[currPos][key[idx]-'a'] + totalDistance(nextPos, idx + 1, key, n, clockWiseDistance, antiClockWiseDistance);

        // move anti-clockWise
        nextPos = (currPos - antiClockWiseDistance[currPos][key[idx]-'a']+n) % n;
        int ans2 = antiClockWiseDistance[currPos][key[idx]-'a'] + totalDistance(nextPos, idx + 1, key, n, clockWiseDistance, antiClockWiseDistance);


        return ans = min(ans1, ans2);
    }
    void printDistance(vector<vector<int>>& distance) {
        for(char ch = 'a'; ch <= 'z'; ch++) cout << ch << " ";
        cout << endl;
        for(int i = 0; i < distance.size(); i++) {
            for(int val: distance[i]) {
                if(val == INT_MAX) {
                    cout << "I ";
                } else 
                cout << val << " ";
            }
            cout << endl;
        }
    }
public:
    int findRotateSteps(string ring, string key) {
        
        int n = ring.length();
        int m = key.length();
        dp = vector<vector<int>> (n, vector<int>(m, -1));
        vector<vector<int>> clockWiseDistance(n, vector<int> (26, INT_MAX));
        vector<vector<int>> antiClockWiseDistance(n, vector<int> (26, INT_MAX));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < 2 * n; j++) {
                if(clockWiseDistance[i][ring[j % n]-'a'] == INT_MAX) {
                    clockWiseDistance[i][ring[j % n]-'a'] = (j - i + n + n ) % n;
                }
            }
        }

        // printDistance(clockWiseDistance);

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j >= 0 - n; j--) {
                if(antiClockWiseDistance[i][ring[(j+n)%n]-'a'] == INT_MAX) {
                    antiClockWiseDistance[i][ring[(j+n)%n]-'a'] = (i - j+n)%n;
                }
            }
        }

        return key.length() + totalDistance(0, 0, key, n, clockWiseDistance, antiClockWiseDistance);
    }
};



