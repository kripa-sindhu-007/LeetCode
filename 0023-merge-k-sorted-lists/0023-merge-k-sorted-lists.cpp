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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() < 1)
            return nullptr;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>        // By default pq is a max heap
            pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummyHead = new ListNode(INT_MIN);
        ListNode* curr = dummyHead;

        if (pq.size() < 1)
            return nullptr;

        while (!pq.empty()) {
            auto curr_node = pq.top();
            pq.pop();
            curr->next = curr_node.second;
            curr = curr_node.second;
            if (curr_node.second->next != nullptr)
                pq.push({curr_node.second->next->val, curr_node.second->next});
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};