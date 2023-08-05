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
         void fs(ListNode *head)
        {
            if(head==NULL or head->next ==NULL) return;
            if(head->val==head->next->val)
            {
                head->next=head->next->next; //skipping
                fs(head);
            }
            else 
            {
                head=head->next;
                fs(head);
            }
        }

  ListNode* deleteDuplicates(ListNode* head) {
        auto a=head;
        fs(head);
        return a;
        
    }
};