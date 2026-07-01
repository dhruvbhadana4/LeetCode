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
    vector<int> ans;

    void postorder(TreeNode* froot){
        if(froot == NULL){
            return;
        }
        postorder(froot->left);
        postorder(froot->right);
        ans.push_back(froot->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    
    }
};