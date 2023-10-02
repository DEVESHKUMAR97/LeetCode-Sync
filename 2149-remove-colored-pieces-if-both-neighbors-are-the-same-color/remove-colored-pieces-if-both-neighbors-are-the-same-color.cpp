class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int aliceMoves = 0, bobMoves = 0;
        char prev = colors[0];
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(colors[i] == prev) {
                cnt++;
            } else {
                if(cnt - 2 > 0) {
                    if(prev == 'A') {
                        aliceMoves += cnt - 2;
                    } else {
                        bobMoves += cnt - 2;
                    }
                }

                prev = colors[i];
                cnt = 1;
            }
        }
        if(cnt - 2 > 0) {
            if(prev == 'A') {
                aliceMoves += cnt - 2;
            } else {
                bobMoves += cnt - 2;
            }
        }
        if(aliceMoves > bobMoves) return true;
        return false;
    }
};