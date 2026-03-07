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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* curr = head;
        ListNode* next1 = head->next;
        curr->next = nullptr;
        while(next1!=nullptr){
            ListNode* temp = next1;
            next1 = next1->next;
            temp->next = curr;
            curr = temp;
        }
        return curr;
    }
};