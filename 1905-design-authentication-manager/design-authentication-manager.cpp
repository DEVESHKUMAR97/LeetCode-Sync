class AuthenticationManager {

private:
    struct compare
    {
        bool operator()(pair<string, int> p1, pair<string, int> p2)
        {
            return p1.second > p2.second;
        }
    };
    
    int ttl;
    unordered_map<string, int> ump;
    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;

public:
    AuthenticationManager(int timeToLive) 
    {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) 
    {
        ump[tokenId] = currentTime + ttl;
        pq.push({tokenId, currentTime + ttl});
    }

    void renew(string tokenId, int currentTime) 
    {
        if(ump.find(tokenId) != ump.end() && ump[tokenId] > currentTime)
        {
            ump[tokenId] = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) 
    {
        while (!pq.empty()) 
        {
            int originalExpiryTime = pq.top().second;
            string tokenId = pq.top().first;
            if (originalExpiryTime > currentTime)
            {
                break;
            }

            pq.pop();
            int actualExpiryTime = ump[tokenId];
            if (actualExpiryTime > currentTime)
            {
                pq.push({tokenId,actualExpiryTime});
            }
        }
        return pq.size();
    }
};