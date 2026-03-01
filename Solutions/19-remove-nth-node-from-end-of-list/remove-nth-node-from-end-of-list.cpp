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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        int pos = size - n;
        if(pos == 0){
            return head->next;
        }
        ListNode* curr = head;
        while(pos > 1){
            curr = curr->next;
            pos--;
        }
        curr->next = curr->next->next;
        return head;
    }
};