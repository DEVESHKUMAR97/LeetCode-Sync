class Solution {
public:
    string simplifyPath(string s) {
        vector<string> directories;
        bool prevSlash = true;
        string ans = "/";
        string directory = "";
        int n = s.length();
        for(int i = 1; i < n; i++) {
            if(s[i] == '/') {
                if(prevSlash) continue;
                directories.push_back(directory);
                directory = "";
                prevSlash = true;
            } else if(s[i] == '.' && (i+1 == n || (i + 1 < n && s[i+1] == '/')) && prevSlash) {
                i++;
            } else if(s[i] == '.' && i + 1 < n && s[i+1] == '.' && (i+2 == n || (i + 2 < n && s[i+2] == '/')) && prevSlash) {
                i += 2;
                if(directories.size() > 0) directories.pop_back();
            } else {
                directory.push_back(s[i]);
                prevSlash = false;
            }
        }
        if(directory != "") directories.push_back(directory);
        for(string& dir: directories) {
            ans += dir;
            ans += '/';
        }
        if(ans.length() != 1) ans.pop_back();
        return ans;
    }
};