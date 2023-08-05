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
void insertlast(ListNode *head,int val)
   {
    auto temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=new ListNode(val,nullptr);

   }
 

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto  h1=list1;
        auto h2=list2;
        ListNode *ans =new ListNode();  //poiting towards first of ans
        while(h1!=nullptr and h2!=nullptr)
        {
            if(h1->val>=h2->val)
            {
                insertlast(ans,h2->val);
                h2=h2->next;
            }
            else
            {
                insertlast(ans,h1->val);
                {
                    h1=h1->next;
                }
            }
        }
        while(h1!=NULL)
        {
            insertlast(ans,h1->val);
            h1=h1->next;
        }
         while(h2!=NULL)
        {
            insertlast(ans,h2->val);
            h2=h2->next;
        }
        ans=ans->next;
        return ans;

    }
};