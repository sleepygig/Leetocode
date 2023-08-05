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
    ListNode* middleNode(ListNode* head) {
        int cnt =0;
        auto temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        
            int i=(cnt/2)+1;
            int j=1;
            auto s=head;
            while(i>j)
            {
                s=s->next;
                j++;
            }
            return s;
        
    }
};