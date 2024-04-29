class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push_back(i);
            else if(s[i] == ')' && st.size() > 0 && s[st.back()] == '(') st.pop_back();
            else if(s[i] == ')') st.push_back(i);
        }
        string ans;
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(j < st.size() && i == st[j]) {
                j++;
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};