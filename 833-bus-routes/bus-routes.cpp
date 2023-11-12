class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        int numberOfBuses = routes.size();
        int numberOfStops = 0;

        unordered_map<int, vector<int>> busStopToBusId;
        for(int i = 0; i < numberOfBuses; i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                busStopToBusId[routes[i][j]].push_back(i);
                numberOfStops++;
            }
        }

        vector<int> busVisited(numberOfBuses, false);
        // vector<int> stopsVisited(numberOfStops, false);

        queue<int> qu;
        // busVisited[busStopToBusId[source]] = true;
        // stopsVisited[source] = true;
        qu.push(source);

        for(int level = 0; qu.size(); level++) {
            for(int k = qu.size(); k > 0; k--) {
                int currStop = qu.front(); qu.pop();
                if(currStop == target) return level;
                for(int busId: busStopToBusId[currStop]) {
                    if(busVisited[busId] == false) {
                        busVisited[busId] = true;
                        for(int stop : routes[busId]) {
                            if(stop != currStop) {
                                qu.push(stop);
                            }
                        }
                    }
                }

            }
        }
        return -1;


    }
};