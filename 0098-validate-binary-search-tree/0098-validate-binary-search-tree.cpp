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
    bool isValidBST(TreeNode* root,TreeNode* right=NULL,TreeNode* left=NULL) {
        /*if(root==NULL)
        {
            return true ;
        }
        
        if(root->left!=NULL and root->left->val >= root->val)
        {
            return false;
        }
        
        if(root->right!=NULL and root->right->val <= root->val)
        {
            return false ;
        }
        
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);
        
        if(left && right)
        {
            return true ;
        }
        else
        {
            return false;
        }*/
       
        if(root==NULL) return true;
		
        if(left!=NULL && root->val<=left->val) return false;
        if(right!=NULL && root->val>=right->val) return false;
        
        return isValidBST(root->left,root,left) && isValidBST(root->right,right,root);
    }
};