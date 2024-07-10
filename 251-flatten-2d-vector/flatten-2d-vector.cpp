class Vector2D {
public:
    vector<vector<int>> vec;
    int row{}, col{};
    int n{};
    Vector2D(vector<vector<int>>& vec): vec(vec) {
        this->n = vec.size();
        while(row < n && vec[row].size() == 0) {
            row++;
        }
    }
    
    int next() {
        int res = vec[row][col];
        if (col == vec[row].size() - 1) {
            row++; col = 0;
            while(row < n && vec[row].size() == 0) {
                row++;
            }
        } else {
            col++;
        }
        return res;
    }
    
    bool hasNext() {
        return row < n;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */