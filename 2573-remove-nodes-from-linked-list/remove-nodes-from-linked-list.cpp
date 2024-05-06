/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = head->next;
        while(currNode != nullptr) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            if(nextNode!=nullptr)
            nextNode = nextNode -> next;
        }
        return prevNode;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        int mx = head->val;
        ListNode* temp = head;
        while(temp->next != nullptr) {
            if(temp->next->val < mx) {
                ListNode* toDel = temp->next;
                temp->next = toDel -> next;
                delete(toDel);
            } else {
                mx = temp->next->val;
                temp = temp -> next;
            }
        }
        return reverseList(head);
    }
};