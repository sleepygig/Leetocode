/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   int LofCyc(ListNode *head)
    {
        auto s=head;
        auto f=head;
        while(f!=NULL and f->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
            if(s==f) 
            {
                int cnt=1;
                s=s->next;
                while(f!=s)
                {
                    s=s->next;
                    cnt++;
                }   
                return cnt;
            }
        }
        return 0;
    }
 
 ListNode *detectCycle(ListNode *head) {
        auto i=head;
        auto j=head;
        int loc=LofCyc(head);
        if(loc==0) return NULL;
        while(loc>0)
        {
            i=i->next;
            loc--;
        }
        while(i!=j)
        {
            i=i->next;
            j=j->next;
        }
        return i;
    }
};