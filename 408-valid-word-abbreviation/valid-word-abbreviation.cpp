class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; int j = 0;
        int num = 0;
        bool prevDigit = false;
        while(j < abbr.length()) {
            if(abbr[j] >= '0' && abbr[j] <= '9') {
                if(num == 0 && abbr[j] == '0') return false;
                num = num * 10 + (abbr[j] - '0');
                prevDigit = true;
            } else {
                if(prevDigit == true) {
                    i += num;
                    num = 0;
                }
                if(i >= word.length() || word[i] != abbr[j]) return false;
                i++;
                prevDigit = false;
            }
            j++;
        }
         if(prevDigit == true) {
                    i += num;
                    num = 0;
                }
        if(i != word.length()) return false;
        return true;
    }
};