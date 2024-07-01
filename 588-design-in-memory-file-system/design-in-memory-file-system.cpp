class Directory {
    public:
    unordered_map<string, string> files;
    unordered_map<string, Directory*> children;
};
class FileSystem {
    Directory* root;
public:
    FileSystem() {
        root = new Directory();
    }
    
    vector<string> ls(string path) {
        Directory *curr = root;
        int start = 1;
        int index = path.find('/', start);
        while(index != -1) {
            string parentPath = path.substr(start, index - start);
            curr = curr -> children[parentPath];
            start = index + 1;
            index = path.find('/', start);
        }
        string finalPath = path.substr(start, path.length() - start);
        // cout << finalPath << endl;
        if(finalPath != "" && !curr -> children.count(finalPath)) {
            // if(curr->files.count(finalPath))
                return {finalPath};
            // return {};
        }
        if(finalPath != "")
            curr = curr -> children[finalPath];
        vector<string> ans;
        for(auto& e: curr->files) {
            ans.push_back(e.first);
        }
        for(auto& e: curr->children) {
            ans.push_back(e.first);
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
    
    void mkdir(string path) {
        Directory *curr = root;
        int start = 1;
        int index = path.find('/', start);
        while(index != -1) {
            string parentPath = path.substr(start, index - start);
            if(!curr -> children.count(parentPath)) {
                curr -> children[parentPath] = new Directory();
            }
            curr = curr -> children[parentPath];
            start = index + 1;
            index = path.find('/', start);
        }
        string finalPath = path.substr(start, path.length() - start);
        if(finalPath != "" && !curr -> children.count(finalPath)) {
            curr -> children[finalPath] = new Directory();
        }
    }
    
    void addContentToFile(string filePath, string content) {
        Directory *curr = root;
        int start = 1;
        int index = filePath.find('/', start);
        while(index != -1) {
            string parentPath = filePath.substr(start, index - start);
            if(!curr -> children.count(parentPath)) {
                curr -> children[parentPath] = new Directory();
            }
            curr = curr -> children[parentPath];
            start = index + 1;
            index = filePath.find('/', start);
        }
        string fileName = filePath.substr(start, filePath.length() - start);
        curr->files[fileName] += content;   
    }
    
    string readContentFromFile(string filePath) {
        Directory *curr = root;
        int start = 1;
        int index = filePath.find('/', start);
        while(index != -1) {
            string parentPath = filePath.substr(start, index - start);
            curr = curr -> children[parentPath];
            start = index + 1;
            index = filePath.find('/', start);
        }
        string fileName = filePath.substr(start, filePath.length() - start);
        return curr->files[fileName]; 
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */