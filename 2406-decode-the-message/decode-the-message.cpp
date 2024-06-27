class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char currChar = 'a';
        for(char ch: key) {
            if(ch != ' ') {
                if(!mp.count(ch)) {
                    mp[ch] = currChar++;
                }
            }
        }

        string ans = "";
        for(char ch: message) {
            if(ch != ' ') {
                ans += mp[ch];
            } else {
                ans += ' ';
            }
        }
        return ans;
        
    }
};