class ProductOfNumbers {
    vector<int> prefixProd;
public:
    ProductOfNumbers() {
        prefixProd = {1};
    }
    
    // O(1)
    void add(int num) {
        if(num > 0) {
            prefixProd.push_back(num * prefixProd.back());
        } else {
            prefixProd = {1};
        }
    }
    

    // O(1)
    int getProduct(int k) {
        int n = prefixProd.size();
        if(k < n) {
            return prefixProd[n-1] / prefixProd[n-k-1];
        } else {
            return 0;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */