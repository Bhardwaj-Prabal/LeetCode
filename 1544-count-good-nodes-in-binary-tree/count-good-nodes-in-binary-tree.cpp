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

    void solve(TreeNode *root,int largest,int &count){
        if(root==NULL) return ;

        if(root->val >= largest){
            count++;
            largest=root->val;
        }

        solve(root->left,largest,count);
        solve(root->right,largest,count);

        return ;

    }
    int goodNodes(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return 1;
        int count=0;

        solve(root,INT_MIN,count);

        return count;

    }
};