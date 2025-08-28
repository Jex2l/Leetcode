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

class compare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        // Seed the heap with non-null heads
        for (ListNode* node : lists) {
            if (node) minHeap.push(node);
        }

        if (minHeap.empty()) return nullptr;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            if (node->next) {
                minHeap.push(node->next);
            }
        }

        return head;
    }
};