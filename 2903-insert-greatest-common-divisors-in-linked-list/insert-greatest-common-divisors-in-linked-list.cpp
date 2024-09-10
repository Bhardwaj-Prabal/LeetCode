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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* curr=head;

        if(head->next==NULL) return head;

        while(curr->next!=NULL){
            int value=0;
            if(curr->next){
                 value= gcd(curr->val,curr->next->val);
            }
            
            ListNode* temp= new ListNode(value,curr->next);

            curr->next=temp;
            curr= temp->next;

        }
        return head;
    }
};