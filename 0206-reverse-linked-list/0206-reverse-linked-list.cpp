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

ListNode* rev(ListNode*&head)
{
    if(head==nullptr or head->next==nullptr) return head;
    auto s=rev(head->next);  //reverse ll ka head
    ListNode *temp;
    temp=s;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->next=nullptr;
    return s;



}


 ListNode* reverseList(ListNode* head) {
 
      
   return rev(head);

    
}
    
};