// Approach 1: Designing Singly LinkedList
// class ListNode {
//     public:
//     int val;
//     ListNode* next;
//     ListNode(int val) {
//         this->val = val;
//         this->next = nullptr;
//     }
// };
class MyLinkedList {
    ListNode *start, *last;
    int size;
public:
    MyLinkedList() {
        start = last = nullptr;
        size = 0;  
    }
    
    int get(int index) {
        if(index >= size) return -1;
        ListNode* curr = start;
        while(index--) {
            curr = curr -> next;
        }
        return curr -> val;
        
    }
    
    void addAtHead(int val) {
        ListNode* n = new ListNode(val);
        if(start == nullptr) {
            start = last = n;
            size = 1;
        } else {
            n -> next = start;
            start = n;
            size++;
        }
    }
    
    void addAtTail(int val) {
        if(last == nullptr) {
            addAtHead(val);
        } else {
            ListNode* n = new ListNode(val);
            last->next = n;
            last = last -> next;
            size++;
        }
        
    }
    
    void addAtIndex(int index, int val) {
        if(index == size) {
            addAtTail(val);
        } else if(index == 0) {
            addAtHead(val);
        } else if(index < size) {
            index--;
            ListNode* n = new ListNode(val);
            ListNode* currNode = start;
            while(index--) {
                currNode = currNode -> next;
            }
            n -> next = currNode -> next;
            currNode -> next = n;
            size++;
        }
        
    }
    
    void deleteAtHead() {
        ListNode* temp = start;
        if(start == last) {
            start = last = nullptr;
        } else {
            start = start -> next;
        }
        size--;
        delete temp;
    }

    void deleteAtLast() {
        ListNode* currNode = start;
        while(currNode -> next != last) {
            currNode = currNode -> next;
        }
        last = currNode;
        currNode = currNode -> next;
        size--;
        delete currNode;
    }


    void deleteAtIndex(int index) {
        if(index == 0) {
            deleteAtHead();
        } else if(index == size - 1) {
            deleteAtLast();
        } else if(index < size) {
            size--;
            index--;
            ListNode* currNode = start;
            while(index--) {
                currNode = currNode -> next;
            }
            ListNode* temp = currNode -> next;
            currNode -> next = temp -> next;
            delete temp;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */