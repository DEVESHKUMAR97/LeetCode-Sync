class Solution {
    void countSort(string& vowS) {
        vector<int> freq(52, 0);
        for(char ch: vowS) {
            if(ch >= 'A' && ch <= 'Z') freq[ch-'A']++;
            else freq[ch-'a'+26]++;
        }
        vowS = "";
        for(int i = 0; i < 52; i++) {
            while(freq[i] > 0) {
                if(i < 26) vowS.push_back(char('A'+i));
                else vowS.push_back('a'+i-26);
                freq[i]--;
            }
        }
    }
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    string sortVowels(string s) {
        string vowS;
        string t = s;
        int n = s.length();
        vector<bool> isVow(n, false);
        for(int i = 0; i < n; i++) {
            if(isVowel(s[i])) {
                isVow[i] = true;
                vowS.push_back(s[i]);
            }
        }
        
        // normal sorting O(n*log(n))
        // sort(vowS.begin(), vowS.end(), [](const char& a, const char& b) {
        //     return a < b;
        // }); // EOee

        // count sort O(n)
        countSort(vowS);
        // cout << vowS << endl; // eeEO
        
        for(int i = 0, j = 0; i < n; i++) {
            if(isVow[i]) {
                t[i] = vowS[j++];
            }
        }
        return t;
        
    }
};