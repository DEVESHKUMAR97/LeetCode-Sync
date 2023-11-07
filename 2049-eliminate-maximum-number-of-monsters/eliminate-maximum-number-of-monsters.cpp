class Solution {
public:

    // approach 1: sorting
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arrivals(n+1, 0);
        for (int i = 0; i < dist.size(); i++) {
            int time = ceil((float) dist[i] / speed[i]);
            if(time > n) time = n;
            arrivals[time]++;
        }
        
        int shot = 0;
        int monsters = 0;
        for (shot = 0; shot < n; shot++) {
            monsters += arrivals[shot];
            if(monsters > shot) break;
        }
        
        return shot;
    }

    // // approach 1: sorting
    // int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    //     vector<float> arrival;
    //     for (int i = 0; i < dist.size(); i++) {
    //         arrival.push_back((float) dist[i] / speed[i]);
    //     }
        
    //     sort(arrival.begin(), arrival.end());
    //     int ans = 0;
        
    //     for (int i = 0; i < arrival.size(); i++) {
    //         // cout << arrival[i] << " ";
    //         if (arrival[i] <= i) {
    //             // cout << "Hello\n";
    //             break;
    //         }
            
    //         ans++;
    //     }
        
    //     return ans;
    // }
};