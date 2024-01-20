class Solution {
    vector<int> prevNearestEqualOrSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(st.size() > 0 && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if(st.size() == 0) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nextNearestSmaller(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() > 0 && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if(st.size() == 0) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    void print(vector<int>& arr) {
        for(int v: arr) cout << v << " ";
        cout << endl;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        vector<int> a1 = nextNearestSmaller(arr);
        vector<int> a2 = prevNearestEqualOrSmaller(arr);

        // print(a1);
        // print(a2);

        long long ans = 0;

        for(int i = 0; i < arr.size(); i++) {
            ans = (ans + ((((1LL) * (a1[i] - i) * (i-a2[i])) % mod) * arr[i]) % mod) % mod;
        }
        return ans;
    }
};