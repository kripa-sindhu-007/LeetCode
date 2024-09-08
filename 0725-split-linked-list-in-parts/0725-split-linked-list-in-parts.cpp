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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sizeLL = 0;

        ListNode* dummy = head;
        while (dummy) {
            sizeLL++;
            dummy = dummy->next;
        }

        int base_size = sizeLL / k;
        int extra_node = sizeLL % k;

        vector<ListNode*> ans(k, NULL);
        dummy = head;

        for (int i = 0; dummy && i < k; i++) {
            ans[i] = dummy;
            int size = base_size + ((extra_node > 0) ? 1 : 0);
            extra_node--;

            for (int j = 1; j < size; j++) {
                dummy = dummy->next;
            }
            ListNode* temp = dummy->next;
            dummy->next = NULL;
            dummy = temp;
        }
        return ans;
    }
};