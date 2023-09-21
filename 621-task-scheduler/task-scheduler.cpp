class Solution {
public:
    // O(n * log(n)). | O(26)
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> prevTimes(26, -1000);
        unordered_map<char, int> freq;
        for(char& ch: tasks) freq[ch]++;

        priority_queue<pair<int, int>> maxHeap;
        queue<pair<int, int>> waitingTasks;

        for(auto& e: freq) {
            maxHeap.push({e.second, e.first - 'A'});
        }

        int timer = 0;
        while(maxHeap.size() > 0 || waitingTasks.size() > 0) {
            timer++;
            while(waitingTasks.size() > 0 && prevTimes[waitingTasks.front().second] < timer - n) {
                maxHeap.push(waitingTasks.front());
                waitingTasks.pop();
            }
            if(maxHeap.size() > 0) {
                auto tp = maxHeap.top(); maxHeap.pop();
                prevTimes[tp.second] = timer;
                if(tp.first > 1) {
                    waitingTasks.push({tp.first - 1, tp.second});
                }
            } else {
                // optimization
                if(waitingTasks.size() > 0) {
                    // cout << "Hello\n";
                    timer = prevTimes[waitingTasks.front().second] + n;
                }
            }
        }
        return timer;
    }
};