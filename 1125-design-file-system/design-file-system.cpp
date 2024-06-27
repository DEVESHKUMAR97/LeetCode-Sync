class Trie {
    public:
    unordered_map<string, Trie*> children;
    int val;
    Trie(int val) {
        this->val = val;
    }
};

class FileSystem {
    Trie* root;
public:
    FileSystem() {
        root = new Trie(-1);
    }
    
    bool createPath(string path, int value) {
        Trie* curr = root;
        int start = 1;
        int index = path.find('/', start);
        // cout << start<< " " << index << endl;
        while(index != -1) {
            string parentPath = path.substr(start, index - start);
            // cout << parentPath << endl;
            if(!curr->children.count(parentPath)) {
                return false;
            }
            curr = curr -> children[parentPath];
            start = index + 1;
            index = path.find('/', start);
        }
        string finalPath = path.substr(start, path.length() - start);
        if(curr->children.count(finalPath)) return false;
        curr -> children[finalPath] = new Trie(value);
        return true;
    }
    
    int get(string path) {
        Trie* curr = root;
        int start = 1;
        int index = path.find('/', start);
        while(index != -1) {
            string parentPath = path.substr(start, index - start);
            if(!curr->children.count(parentPath)) {
                return -1;
            }
            curr = curr -> children[parentPath];
            start = index + 1;
            index = path.find('/', start);
        }
        string finalPath = path.substr(start, path.length() - start);
        if(!curr->children.count(finalPath)) return -1;
        curr = curr -> children[finalPath];
        return curr->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */