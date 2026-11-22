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
public:
ListNode* find(ListNode* head,int k){
    while(head && k>1){
        head = head->next;
        k--;
    }
    return head;
}
ListNode* reverse_list(ListNode* head){
    ListNode* prev = nullptr;

    while(head){
        ListNode* next_node = head->next;
        head->next = prev;
        prev = head;
        head = next_node;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        while(temp){
            ListNode* kth_node = find(temp,k);
            if(kth_node==nullptr){
                prev->next = temp;
                break;
            }
            ListNode* next_node = kth_node->next;
            kth_node->next = nullptr;
            kth_node = reverse_list(temp);
            
            if(head==temp){
                head = kth_node;
            }else{
                prev->next = kth_node;
            }
            prev = temp;
            temp = next_node;

        }
        return head;
    }
};
