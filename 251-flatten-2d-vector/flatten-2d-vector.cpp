class Vector2D {
    vector<vector<int>> vec;
    int row, col, n;
public:
    Vector2D(vector<vector<int>>& vec): vec(vec){
        row = 0;
        col = 0;
        n = vec.size();
    }
    
    int next() {
        if(hasNext()) {
            return vec[row][col++];
        }
        return -1;
        
    }
    
    bool hasNext() {
        if(row < n && col < vec[row].size()) return true;
        while(row < n && col >= vec[row].size()) {
            col = 0;
            row++;
        }

        return row < n;
        
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

