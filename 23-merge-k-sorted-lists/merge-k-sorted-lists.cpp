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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

      priority_queue<int, vector<int>, greater<int> > pq;
      if(lists.size()==0){
          return NULL;
      }

        for(int i=0 ;i<lists.size(); i++){
            ListNode * temp= lists[i];
            if(temp==NULL){
                continue;
            }
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;

            }
        }
        if(pq.empty()==true) return NULL;
        ListNode *head= new ListNode(pq.top());
        pq.pop();
        if(head==NULL){
            return NULL;
        }

        ListNode* curr=head;
        while(pq.empty()!=true){
            if(pq.empty()==true){
                return head;
            }

            curr->next= new ListNode(pq.top());
            pq.pop();
            curr=curr->next;

            
        }
        return head;
    }
};