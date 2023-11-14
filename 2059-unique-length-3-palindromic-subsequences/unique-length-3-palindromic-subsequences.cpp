class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<string> st;
        vector<int> freq(26, 0);
        for(char ch: s) freq[ch - 'a']++;

        vector<int> preFreq(26, 0);
        preFreq[s[0] - 'a']++;
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                int leftFreq = preFreq[ch - 'a'];
                int rightFreq = freq[ch - 'a'] - leftFreq;
                if(ch == s[i]) rightFreq--;
                if(rightFreq > 0 && leftFreq > 0) {
                    string temp = "";
                    temp.push_back(ch);
                    temp.push_back(s[i]);
                    temp.push_back(ch);
                    st.insert(temp); 
                }
            }
            preFreq[s[i] - 'a']++;
        }
        return st.size();
    }
};