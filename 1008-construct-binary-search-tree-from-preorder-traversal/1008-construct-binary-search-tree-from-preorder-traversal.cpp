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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            TreeNode* nun = root;
            TreeNode* new1 = new TreeNode(preorder[i]);

            while(true){
                if(nun->val > new1->val){
                    if(nun->left==NULL){
                        nun->left = new1;
                        break;
                    }
                    nun = nun->left;
                }
                else{
                    if(nun->right==NULL){
                        nun->right = new1;
                        break;
                    }
                    nun = nun->right;
                }
            }
        }
        return root;
    }
};