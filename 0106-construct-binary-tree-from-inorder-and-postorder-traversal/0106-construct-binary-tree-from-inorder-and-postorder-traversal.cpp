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
    TreeNode* build(vector<int> & inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int,int>& mpp){
        if(instart>inend || poststart>postend) return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot= mpp[root->val];
        int numsleft = inroot- instart;

        root->left = build(inorder, instart, inroot-1, postorder, poststart, poststart+numsleft-1, mpp);
        root->right = build(inorder, inroot+1, inend, postorder, poststart+numsleft, postend -1, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
    }
};