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

    void make_vector(TreeNode *root,vector<int>&treeVec){
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL){
            treeVec.push_back(root->val);
        }

        make_vector(root->left,treeVec);
        make_vector(root->right,treeVec);


    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;

        make_vector(root1,tree1);
        make_vector(root2,tree2);
        int n=tree1.size();
        int m=tree2.size();

        if(n!=m) return false;

        for(int i=0;i<n;i++){
            if(tree1[i]!= tree2[i]) return false;
        }

        return true;
    }
};