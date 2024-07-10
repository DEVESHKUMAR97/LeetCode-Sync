class CombinationIterator {
    string permutation, characters;
    int n, req;
    bool hasNextBro;
public:
    CombinationIterator(string characters, int combinationLength) {
        n = characters.size();
        req = combinationLength;
        permutation = string(req, '1');
        permutation += string(n - req, '0');
        cout << permutation << endl;
        this->characters=characters;
        hasNextBro = true;
    }
    
    string next() {
        if(hasNextBro) {
            string ans = "";
            for(int i = 0; i < n; i++) {
                if(permutation[i] == '1') ans += characters[i];
            }
            hasNextBro = prev_permutation(permutation.begin(), permutation.end());
            return ans;
        }
        return "";

    }
    
    bool hasNext() {
        return hasNextBro;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//  abcd
//  1100
//  1010