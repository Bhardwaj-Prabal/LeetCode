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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *curr = head;
        int count = 0;
        
        
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        
        int quotient = count / k;   
        int remainder = count % k;  
        
      
        vector<ListNode*> result(k, nullptr);
        curr = head;
        for (int i = 0; i < k && curr != nullptr; ++i) {
            result[i] = curr;
            int partSize = quotient + (remainder > 0 ? 1 : 0); 
            remainder--;

            
            for (int j = 1; j < partSize; ++j) {
                if (curr != nullptr) {
                    curr = curr->next;
                }
            }
            
            
            if (curr != nullptr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;  
                curr = nextPart;       
            }
        }
        
        return result;
    }
};
