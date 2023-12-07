class Solution {
public:
    string largestOddNumber(string num) {
        int index = num.length() - 1;
        for(; index >= 0; index--) {
            if((num[index] - '0') % 2 == 1) {
                break;
            }
        }
        return num.substr(0, index + 1);
    }
};