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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Edge case: if the head is nullptr, return nullptr
        if (!head) return nullptr;
        
        // Queue to store filtered nodes
        queue<ListNode*> q;
        ListNode* curr = head;
        set<int> st(nums.begin(),nums.end());

      
        while (curr != nullptr) {
            if (st.find(curr->val)==st.end()) {
                q.push(curr);
            }
            curr = curr->next;
        }

        
        ListNode* headMain = nullptr;
        ListNode* tail = nullptr;

        while (!q.empty()) {
            if (!headMain) {
                headMain = q.front();
                tail = headMain;
                q.pop();
            } else {
                tail->next = q.front();
                tail = tail->next;
                q.pop();
            }
        }

        
        if (tail) {
            tail->next = nullptr;
        }

        return headMain;
    }
};
