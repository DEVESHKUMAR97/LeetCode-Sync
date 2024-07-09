class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int chefBusyTill = 0;
        double wait = 0;
        for(auto& c: customers) {
            if(c[0] <= chefBusyTill) {
                wait += chefBusyTill - c[0];
                chefBusyTill += c[1];
            } else {
                chefBusyTill = c[0] + c[1];
            }
            wait += c[1];
        }
        return wait / customers.size();
        
    }
};