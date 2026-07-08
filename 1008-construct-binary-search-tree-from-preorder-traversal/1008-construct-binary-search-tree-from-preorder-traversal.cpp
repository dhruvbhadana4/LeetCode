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
    TreeNode* ans(vector<int>& preorder, int pstart, int pend , vector<int>& inorder, int istart, int iend, unordered_map<int,int> &mpp){
        if(pstart > pend || istart > iend) return NULL;
        TreeNode* root = new TreeNode(preorder[pstart]);
        int ind = mpp[root->val];
        int numsleft = ind - istart;

        root->left = ans(preorder, pstart+1, pstart+numsleft, inorder, istart, istart + numsleft -1, mpp);
        root->right = ans(preorder, pstart+numsleft+1, pend, inorder, ind + 1, iend, mpp);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        unordered_map<int,int> mpp;
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        
        return ans(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);

    }
};