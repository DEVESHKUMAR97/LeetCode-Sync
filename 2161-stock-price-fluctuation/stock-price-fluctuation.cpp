class StockPrice {
    unordered_map<int, int> timePrice;
    map<int, int> priceFreq;
    int latestTime;


public:
    StockPrice() {
        timePrice.clear();
        priceFreq.clear();
        latestTime = -1;     
    }
   
    //    O(log(n))
    void update(int timestamp, int price) {
       if(timestamp > latestTime) {
            // newTime Stamp
            timePrice[timestamp] = price;
            priceFreq[price]++;
            latestTime = timestamp;
        } else {
            if(timePrice.count(timestamp)) {
                priceFreq[timePrice[timestamp]]--;
                if(priceFreq[timePrice[timestamp]] == 0) priceFreq.erase(timePrice[timestamp]);
            }
            timePrice[timestamp] = price;
            priceFreq[price]++;	
        }
    }
   
    int current() {
	    return timePrice[latestTime];
       
    }
   
    int maximum() {
        auto itr = priceFreq.end();
        itr--;
        return itr -> first;
    }
   
    int minimum() {
       return priceFreq.begin()->first;
    }
};


/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */



