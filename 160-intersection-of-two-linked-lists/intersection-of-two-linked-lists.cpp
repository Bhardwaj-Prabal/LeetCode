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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        unordered_set<ListNode*> st;

        while (curr1) {
            st.insert(curr1);
            curr1 = curr1->next;
        }
        while (curr2) {
            if (st.find(curr2) != st.end()) {
                return curr2;
            }
            curr2 = curr2->next;
        }

        return NULL;
    }
};