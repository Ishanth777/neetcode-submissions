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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int carry = 0;

        while(l1 && l2){
            int a = l1->val;
            int b = l2->val;
            int sum = a+b+carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while(l1){
            int sum = l1->val + carry;
            temp->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2){
            int sum = l2->val + carry;
            temp->next = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next;
            temp = temp->next;
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return head->next;
    }
};
