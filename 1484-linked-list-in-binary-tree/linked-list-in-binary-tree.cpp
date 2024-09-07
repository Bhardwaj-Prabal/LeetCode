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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void starters(TreeNode* root,vector<TreeNode *>&starts,int val){
        if(root==NULL) return;

        if(root->val==val) starts.push_back(root);

        starters(root->left,starts,val);
        starters(root->right,starts,val);

        return;
    }

    bool isPath(ListNode* head, TreeNode *start) {
    
        if (head == NULL) return true;
        if (start == NULL) return false;

        if (head->val == start->val) {
            return isPath(head->next, start->left) || isPath(head->next, start->right);
        }

    
     return false;
    }


    
    bool isSubPath(ListNode* head, TreeNode* root) {

        vector<TreeNode *> starts;

        starters(root,starts,head->val);

        
       int n= starts.size();

       for(int i=0;i<n;i++){
            bool flag = isPath(head,starts[i]);

            if(flag) return true;
       }


        return false;
        
    }
};