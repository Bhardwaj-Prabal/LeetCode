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
   ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;  // Save the head of the even list to connect later

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;  // Connect the end of odd list to the head of even list
    return head;
}
};