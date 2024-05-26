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
        vector<int>val;
        ListNode* temp=head;
        while(temp!=NULL){
            val.push_back(temp->val);
            temp=temp->next;
        }
        sort(val.begin(),val.end());
        temp=head;
        for(int i=0;i<val.size();i++){
            temp->val=val[i];
            temp=temp->next;
        }
        return head;
        
    }
};