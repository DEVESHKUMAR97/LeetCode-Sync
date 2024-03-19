class Solution {
public:
        // Approach 2: Greedy minimize the number of idle slots
        // O(n)
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch: tasks) {
            freq[ch-'A']++;
        }
        // sorted frequencies in non-increasing order
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = tasks.size();
        int idleTime = (freq[0] - 1) * n; // maximum possible idle time 
        for(int i = 1; i < 26; i++) {
            idleTime -= min(freq[0] - 1, freq[i]);
            if(idleTime < 0) {
                idleTime = 0;
                break;
            }
        }
        return ans + idleTime;

     
    }

    // // O(n * log(26)). | O(26)
    // int leastInterval(vector<char>& tasks, int n) {
    //     vector<int> prevTimes(26, -1000);
    //     unordered_map<char, int> freq;
    //     for(char& ch: tasks) freq[ch]++;

    //     priority_queue<pair<int, int>> maxHeap;
    //     queue<pair<int, int>> waitingTasks;

    //     for(auto& e: freq) {
    //         maxHeap.push({e.second, e.first - 'A'});
    //     }

    //     int timer = 0;
    //     while(maxHeap.size() > 0 || waitingTasks.size() > 0) {
    //         timer++;
    //         while(waitingTasks.size() > 0 && prevTimes[waitingTasks.front().second] < timer - n) {
    //             maxHeap.push(waitingTasks.front());
    //             waitingTasks.pop();
    //         }
    //         if(maxHeap.size() > 0) {
    //             auto tp = maxHeap.top(); maxHeap.pop();
    //             prevTimes[tp.second] = timer;
    //             if(tp.first > 1) {
    //                 waitingTasks.push({tp.first - 1, tp.second});
    //             }
    //         } else {
    //             // optimization
    //             if(waitingTasks.size() > 0) {
    //                 // cout << "Hello\n";
    //                 timer = prevTimes[waitingTasks.front().second] + n;
    //             }
    //         }
    //     }
    //     return timer;
    // }
};