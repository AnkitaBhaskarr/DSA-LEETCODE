class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // Dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // prev points to the node before the pair
        ListNode* prev = dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            
            // First and second nodes of the pair
            ListNode* first = prev->next;
            ListNode* second = first->next;
            
            // Swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move to the next pair
            prev = first;
        }
        
        // New head
        return dummy->next;
    }
};