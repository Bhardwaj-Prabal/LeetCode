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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
       vector<vector<int>> temp(m, vector<int>(n, -1));
        ListNode* curr=head;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {

        for (int i = left; i <= right; ++i) {
            if(curr){
                 temp[top][i] = curr->val;
                curr=curr->next;
            }else{
                temp[top][i]=-1;
            }
            
        }
        top++;

        
        for (int i = top; i <= bottom; ++i) {
            if(curr){
             temp[i][right]=curr->val;
             curr=curr->next;
            }else{
                temp[i][right]=-1;
            }

        }
        right--;


        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                if(curr){
                temp[bottom][i]=curr->val;
                curr=curr->next;
                }else{
                    temp[bottom][i]=-1;
                }


            }
            bottom--;
        }

        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                if(curr){
                    temp[i][left]=curr->val;
                    curr=curr->next;
                }else{
                    temp[i][left]=-1;
                }
               

            }
            left++;
        }
    }
        return temp;
    }
};