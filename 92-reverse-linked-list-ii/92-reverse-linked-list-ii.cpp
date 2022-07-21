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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        
            ListNode* newhead=reverse(head->next);
            head->next->next=head;
            head->next=NULL;
        return newhead;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=1;
        ListNode* temp=head;
        ListNode* leftnode=NULL;
        ListNode* rightnode=NULL;
        
        
        while(count<left)
        {
            leftnode=temp;
            temp=temp->next;
            count++;
        }
        ListNode* start=temp;
        ListNode* end=temp;
        while(count<right)
        {
            
            temp=temp->next;
            end=temp;
            count++;
        }
        rightnode=temp->next;
        end->next=NULL;
        
        ListNode* newhead=reverse(start);
        if(leftnode!=NULL)
        {
            leftnode->next=newhead;
        }
        if(leftnode==NULL)
        {
            head=newhead;
        }
        ListNode* temp1=newhead;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=rightnode;
        return head;
    }
};