class StringIterator {
    int times;
    char curr;
    int index;
    string s;
public:
    StringIterator(string compressedString) {
        times = 0;
        curr = '#';
        index = 0;
        s = compressedString;
    }
    
    char next() {
        if(hasNext()) {
            times--;
            return curr;
        }
        return ' ';
    }
    
    bool hasNext() {
        if(times == 0) {
            if(index == s.length()) return false;
            curr = s[index];
            index++;
            while('0' <= s[index] && s[index] <= '9') {
                times = times * 10 + (s[index] - '0');
                index++;
            }
            return true;
        }
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */