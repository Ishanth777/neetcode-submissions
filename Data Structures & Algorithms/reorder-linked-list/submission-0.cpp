class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* curr = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while(curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        // Step 3: Merge alternately
        ListNode* first = head;
        ListNode* second = prev;

        while(second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};