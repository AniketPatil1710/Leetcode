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
    bool evaluateTree(TreeNode* root) {
        
        if(!root->left and !root->right)
        {
            return root->val ;
        }
        
        int l = evaluateTree(root->left) ;
        int r = evaluateTree(root->right) ;
        
        if(root->val == 2) {
            root->val = l or r;
        }
        else {
            root->val = l and r;
        }
        return root->val;
    }
};