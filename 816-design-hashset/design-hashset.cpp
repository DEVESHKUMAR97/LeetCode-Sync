// Approach 3: Hashing with separate chaining implemented via BSTs
// Time: O(log(N/K)) | O(K + M): where N is the number of all possile values 
// K is the number of buckets (eg. 769)
// M is number of unique values inserted in the hashset
// class TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   public:
//   TreeNode(int val):val(val){
//     left = right = nullptr;
//   }
// };
class BSTree {
  public:
  TreeNode* root;
  TreeNode* predecessor(TreeNode* root) {
    while(root->right) root= root->right;
    return root;
  }
  
  BSTree() {
    root = nullptr;
  }

  TreeNode* searchInBST(TreeNode* root, int val) {
    if(root == nullptr || root->val == val) {
      return root;
    }
    if(root -> val > val) {
      return searchInBST(root->left, val);
    }

    return searchInBST(root->right, val);
  }

  TreeNode* insertInBST(TreeNode* root, int val) {
    if(root == nullptr) {
      return new TreeNode(val);
    }

    if(root->val == val) {
      // skip the insertion
      return root;
    }


    if(root->val > val) {
      root->left = insertInBST(root->left, val);
    } else {
      root->right = insertInBST(root->right, val);
    }
    return root;
  }

  // O(log(N)) | O(H)
  TreeNode* deleteNode(TreeNode* root, int key) {
      if(root == nullptr) return root;

      if(root->val > key) {
          // delete in left
          root->left = deleteNode(root->left, key);
      } else if(root->val < key) {
          // delete in right
          root->right = deleteNode(root->right, key);
      } else {
          // key found
          if(root->left == nullptr && root->right == nullptr) {
              // root is leaf
              delete root;
              return nullptr;
          }
          if(!root->right) {
              // only one child in left side
              TreeNode* subTree = root->left;
              delete root;
              return subTree;
          }
          if(!root->left) {
              // only one child in right side
              TreeNode* subTree = root->right;
              delete root;
              return subTree;
          }

          // both child are present

          // find predecessor / biggest in left subtree
          TreeNode* pred = predecessor(root->left);
          root->val = pred->val;

          // now delete predecessor value node
          root->left = deleteNode(root->left, pred->val);
      }
      return root;
  }
};
class Bucket {
  BSTree bstree;
  public:
  Bucket() {
    // do nothing
  }

  bool search(int key) {
    return nullptr != bstree.searchInBST(bstree.root, key);
  }

  void insert(int key) {
    bstree.root = bstree.insertInBST(bstree.root, key);
  }

  void remove(int key) {
    bstree.root = bstree.deleteNode(bstree.root, key);
  }

};
class MyHashSet {
    vector<Bucket> hashSet;
    int keyRange;

    // O(1)
    int getHash(int key) {
        return key % keyRange;
    }
public:
    MyHashSet() {
        keyRange = 769;
        hashSet = vector<Bucket> (keyRange);
    }

    // O(log(N/K)) for inserting
    void add(int key) {
        Bucket& bucket = hashSet[getHash(key)];
        bucket.insert(key); // if already present, it will skip
    }
    
    // O(log(N/K)) for removing
    void remove(int key) {
        Bucket& bucket = hashSet[getHash(key)];
        bucket.remove(key);
    }
    
    // O(log(N/K)) for searching
    bool contains(int key) {
        Bucket& bucket = hashSet[getHash(key)];
        return bucket.search(key);
    }
};


// // Approach 2: Hashing with separate chaining
// // Time: O(N/K) | O(K + M): where N is the number of all possile values 
// // K is the number of buckets (eg. 769)
// // M is number of unique values inserted in the hashset
// class MyHashSet {
//     vector<list<int>> hashSet;
//     int keyRange;

//     // O(1)
//     int getHash(int key) {
//         return key % keyRange;
//     }

//     // O(N/K)
//     list<int>::iterator searchInBucket(int key, list<int>& bucket) {
//         list<int>::iterator itr = bucket.begin();
//         while(itr != bucket.end()) {
//             if(*itr == key) return itr;
//         }
//         return itr;
//     }
// public:
//     MyHashSet() {
//         keyRange = 769;
//         hashSet = vector<list<int>> (keyRange);
//     }

//     // O(N/K) for searching and O(1) for inserting
//     void add(int key) {
//         list<int>& bucket = hashSet[getHash(key)];
//         if(bucket.end() == searchInBucket(key, bucket)) {
//             bucket.push_front(key);
//         }
        
//     }
    
//     // O(N/K) for searching and O(1) for removing using erase
//     void remove(int key) {
//         list<int>& bucket = hashSet[getHash(key)];
//         auto itr = searchInBucket(key, bucket);
//         if(bucket.end() != itr) {
//             bucket.erase(itr);
//         }
//     }
    
//     // O(N/K) for searching
//     bool contains(int key) {
//         list<int>& bucket = hashSet[getHash(key)];
//         return bucket.end() != searchInBucket(key, bucket);
//     }
// };



// Approach 1: Direct Address Table
// Time: O(1) | Space: O(N)
// class MyHashSet {
// public:
//     vector<bool> hashSet;
//     MyHashSet() {
//         hashSet.resize(1000002, false);
//     }
    
//     void add(int key) {
//         hashSet[key] = true;
//     }
    
//     void remove(int key) {
//         hashSet[key] = false;
//     }
    
//     bool contains(int key) {
//         return hashSet[key];
//     }
// };

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */