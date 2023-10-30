class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        
        // handling minutes
        if(time[3] == '?') {
            ans *= 6;
        }
        if(time[4] == '?') {
            ans *= 10;
        }

        // handling hours
        if(time[0] == '?' && time[1] == '?') {
            ans *= 24;
        } else if(time[0] == '?') {
            if(time[1] <= '3') {
                ans *= 3;
            } else {
                ans *= 2;
            }
        } else if(time[1] == '?') {
            if(time[0] <= '1') {
                ans *= 10;
            } else {
                ans *= 4;
            }
        }
        return ans;
    }
};