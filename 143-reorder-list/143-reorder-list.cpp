class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while(fast && fast -> next)
            slow = slow -> next,
            fast = fast -> next -> next;           
        return slow;                                
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head) {
            auto nextNode = head -> next;           
            head -> next = prev;                    
            prev = head;                            
            head = nextNode;                        
        }
        return prev;                                
    }
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        auto mid = middleNode(head);
        auto R = reverseList(mid), L = head -> next;
        for(int i = 0; L != R; i++, head = head -> next)      
            if(i & 1) {                              
                head -> next = L;
                L = L -> next;
            }
            else {
                head -> next = R;
                R = R -> next;
            }
    }
};