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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lefthead=new ListNode(0);
        ListNode* left=lefthead;
        ListNode* righthead=new ListNode(0);
        ListNode* right=righthead;
        
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                left->next=temp;
                left=left->next;
                temp=temp->next;
                left->next=NULL;
            }
            else
            {
                right->next=temp;
                right=right->next;
                temp=temp->next;
                right->next=NULL;
            }
            
        }
        left->next=righthead->next;
        
        
        return lefthead->next;
    }
};