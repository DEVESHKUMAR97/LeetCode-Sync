class TopVotedCandidate {
    unordered_map<int, int> votes; // person vs votes count
    int winner;
    int maxVotes;
    vector<pair<int, int>> winners;  // time vs winner at that time
public:
    // precomputed answer + binary search
    // O(n)
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        winner = -1;
        maxVotes = 0;
        for(int i = 0; i < times.size(); i++) {
            votes[persons[i]]++;
            if(votes[persons[i]] >= maxVotes) {
                maxVotes = votes[persons[i]];
                winner = persons[i];
                winners.push_back({times[i], winner});
                // cout << times[i] << ", " << winner << endl;
            }
        }
        
    }
    
    int q(int t) {
        return prev(upper_bound(begin(winners), end(winners), make_pair(t, INT_MAX)))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */