class UnionFind {
    int n;
    vector<int> parent;
    vector<int> rankk;
    int ncc; // number of connected components
    int lcs; // largest component size
    public:
    UnionFind(int n) {
        this->n = n;
        this->ncc = n;
        this->lcs = 1;
        parent = vector<int> (n, -1);
        rankk = vector<int> (n, -1);
    }

    int find(int u) {
        if(parent[u] < 0) return u;
        return parent[u] = find(parent[u]); // path compression
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(rankk[u] >= rankk[v]) {
                parent[u] += parent[v]; // size combining
                parent[v] = u;
                if(rankk[u] == rankk[v]) {
                    rankk[u]++;
                }
                lcs = max(lcs, abs(parent[u]));
            } else {
                parent[v] += parent[u]; // size combining
                parent[u] = v;
                lcs = max(lcs, abs(parent[v]));
            }
            ncc--; // 2 diffrent components are combining 
            return true;
        }
        return false;
    }

    // number of connected components
    int getNCC() {
        return ncc;
    }

    // largest component size
    int getLCS() {
        return lcs;
    }

    // return the size of connected component of node u
    int getSizeOfCC(int u) {
        u = find(u);
        return abs(parent[u]);
    }

    void printParent() {
        for(int p: parent) {
            cout << p << ", ";
        }
        cout << endl;
    }

    void printRank() {
        for(int r: rankk) {
            cout << r << ", ";
        }
        cout << endl;
    }
};
class Solution {
    vector<int> isPrime;
    vector<int> genPrimes(int n) {
        isPrime[0] = isPrime[1] = 0;
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i] == 1) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        vector<int> primes;
        for(int i = 1; i <= n; i++) {
            if(isPrime[i])
            primes.push_back(i);
        }
        return primes;
    }
//     long long dfs(int u, vector<int>* adj, long long& finalAns, int par) {
        
//         vector<long long> temp;
//         long long size = 0;
//         for(int v: adj[u]) {
//             if(v != par && isPrime[v] == false) {
//                 temp.push_back(dfs(v, adj, finalAns, u));
//                 size += temp.back();
//             }
//         }
        
//         if(isPrime[u] == 1) {
//             long long totalSum = accumulate(temp.begin(), temp.end(), 0);
//             finalAns += totalSum;
//             for(int i = 0; i < temp.size(); i++) {
//                 totalSum -= temp[i];
//                 finalAns += totalSum * temp[i];
//             }
//             return 0;
//         }
//         return size + 1;
        
//     }
    long long count(int u, vector<int>* adj, UnionFind& uFind) {
        vector<long long> compositeGroupSizes;
        for(int v: adj[u]) if(!isPrime[v]) {
            compositeGroupSizes.push_back(uFind.getSizeOfCC(v));
        }
        long long ans = 0;
        long long totalSum = accumulate(compositeGroupSizes.begin(), compositeGroupSizes.end(), 0);
        ans += totalSum;
        for(int i = 0; i < compositeGroupSizes.size(); i++) {
            totalSum -= compositeGroupSizes[i];
            ans += totalSum * compositeGroupSizes[i];
        }
        return ans;
    }
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        if(n <= 1) return 0;
        this->isPrime = vector<int> (n + 1, 1);
        vector<int> primes = genPrimes(n);
        
        UnionFind uFind(n+1);
        
        
        vector<int> adj[n+1];
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            if(isPrime[e[0]] || isPrime[e[1]]) continue;
            
            uFind.merge(e[0], e[1]);
        }
        // uFind.printParent();
        long long ans = 0;
        for(int prime: primes) {
            long long hello = count(prime, adj, uFind);
            // cout << prime << ", " << hello << endl;
            ans += hello;
        }
        // ans += ;
        
        return ans;
        
        
    }
};