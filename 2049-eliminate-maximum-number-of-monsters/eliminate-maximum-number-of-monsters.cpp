class Solution {
public:

    // approach 1: sorting
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> arrival;
        for (int i = 0; i < dist.size(); i++) {
            arrival.push_back((float) dist[i] / speed[i]);
        }
        
        sort(arrival.begin(), arrival.end());
        int ans = 0;
        
        for (int i = 0; i < arrival.size(); i++) {
            // cout << arrival[i] << " ";
            if (arrival[i] <= i) {
                // cout << "Hello\n";
                break;
            }
            
            ans++;
        }
        
        return ans;
    }
};