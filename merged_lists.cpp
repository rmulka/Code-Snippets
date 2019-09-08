
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    void completeList(ListNode* ln, ListNode* curr) {
        if (ln != NULL) {
            while (ln != NULL) {
                curr->next = ln;
                curr = curr->next;
                ln = ln->next;
            }
        }
    }
    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* curr = NULL;
        
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        curr = head;
        
        while(l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if (l1 != NULL) {
            this->completeList(l1, curr);
        }
        else if (l2 != NULL) {
            this->completeList(l2, curr);
        }
        
        return head;
    }
};