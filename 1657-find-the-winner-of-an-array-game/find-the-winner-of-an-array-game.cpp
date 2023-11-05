class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int winnerCount = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < winner) {
                winnerCount++;
            } else {
                winner = arr[i];
                winnerCount = 1;
            }
            if(winnerCount == k) break;
        }
        return winner;
        
    }
};