class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> mp(26, 0);
        char currChar = 'a';
        for(char ch: key) {
            if(ch != ' ') {
                if(mp[ch-'a'] == 0) {
                    mp[ch-'a'] = currChar++;
                }
            }
        }

        string ans = "";
        for(char ch: message) {
            if(ch != ' ') {
                ans += mp[ch-'a'];
            } else {
                ans += ' ';
            }
        }
        return ans;
        
    }
    // string decodeMessage(string key, string message) {
    //     unordered_map<char, char> mp;
    //     char currChar = 'a';
    //     for(char ch: key) {
    //         if(ch != ' ') {
    //             if(!mp.count(ch)) {
    //                 mp[ch] = currChar++;
    //             }
    //         }
    //     }

    //     string ans = "";
    //     for(char ch: message) {
    //         if(ch != ' ') {
    //             ans += mp[ch];
    //         } else {
    //             ans += ' ';
    //         }
    //     }
    //     return ans;
        
    // }
};