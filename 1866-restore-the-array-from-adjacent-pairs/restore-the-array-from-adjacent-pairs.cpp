class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for(auto& pp: adjacentPairs) {
            adj[pp[0]].push_back(pp[1]);
            adj[pp[1]].push_back(pp[0]);
        }

        int start;
        for(auto& e: adj) {
            if(e.second.size() == 1) {
                start = e.first;
                break;
            }
        }

        vector<int> ans;
        int curr = start;
        int prev = -1;
        ans.push_back(start);

        while(ans.size() < adjacentPairs.size() + 1) {
            for(auto next: adj[curr]) {
                if(next != prev) {
                    ans.push_back(next);
                    prev = curr;
                    curr = next;
                    break;
                }
            }
        }
        return ans;
    }
};