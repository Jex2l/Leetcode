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

    ListNode* merge_list(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* result = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                result->next = l2;
                l2 = l2->next;
            }
            else {
                result->next = l1;
                l1 = l1->next;
            }
            result = result->next;
        }
        if(l1) result->next = l1;
        else result->next = l2;
        return dummy.next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1) {
            vector<ListNode*> temp;
            for(int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                temp.push_back(merge_list(l1, l2));
            }
            lists = temp;
        }
        return lists[0];
    }
};