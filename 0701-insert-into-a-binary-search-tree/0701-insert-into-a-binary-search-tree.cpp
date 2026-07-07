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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* track = root;
        while(track!=NULL){
            if(track->val<val){
                if(track->right) track = track->right;
                else{
                    TreeNode* last = track;
                    TreeNode* new1 = new TreeNode(val);
                    last->right = new1;
                    break;
                } 
            }
            else{
                if(track->left) track = track->left;
                else{
                    TreeNode* last = track;
                    TreeNode* new1 = new TreeNode(val);
                    last->left = new1;
                    break;
                }
            }
        }
        return root;
    }
};