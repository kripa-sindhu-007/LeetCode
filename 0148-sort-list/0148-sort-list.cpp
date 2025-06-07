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
    ListNode* sortList(ListNode* head) {
        vector<int> listVal;
        ListNode* it = head;
        while (it) {
            listVal.push_back(it->val);
            it = it->next;
        }
        sort(listVal.begin(), listVal.end());
        it = head;
        for (int val : listVal) {
            it->val = val;
            it = it->next;
        }
        return head;
    }
};