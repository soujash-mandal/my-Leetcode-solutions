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
    int length(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        
        return count;
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=length(head);
        int pos=0;
        ListNode* temp=head;
        if(n==l)
        { 
            head=head->next;
            return head;
         }
        while(pos<(l-n-1))
        {
            temp=temp->next;
            pos++;
        }
        
        ListNode* todelete=temp->next;
        if(temp->next!=NULL)
            temp->next=temp->next->next;
        delete todelete;
        return head;
        
    }
};