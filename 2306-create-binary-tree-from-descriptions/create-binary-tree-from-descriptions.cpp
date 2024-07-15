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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
     unordered_map<int, TreeNode*> nodes;
    unordered_set<int> children;

    for (const auto& desc : descriptions) {
        int parentVal = desc[0];
        int childVal = desc[1];
        bool isLeft = desc[2];

        if (nodes.find(parentVal) == nodes.end()) {
            nodes[parentVal] = new TreeNode(parentVal);
        }
        if (nodes.find(childVal) == nodes.end()) {
            nodes[childVal] = new TreeNode(childVal);
        }

        TreeNode* parent = nodes[parentVal];
        TreeNode* child = nodes[childVal];

        if (isLeft) {
            parent->left = child;
        } else {
            parent->right = child;
        }

        children.insert(childVal);
    }

    // Find the root (a node that is never a child)
    for (const auto& desc : descriptions) {
        if (children.find(desc[0]) == children.end()) {
            return nodes[desc[0]];
        }
    }

    return nullptr;
    }
};