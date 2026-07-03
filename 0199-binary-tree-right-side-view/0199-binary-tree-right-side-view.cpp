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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> st;
        vector<int>ans;
        if(root == NULL) return ans;
        st.push(root);
        while(!st.empty()){
            vector<int>level;
            int size = st.size();
            for(int i=0;i<size;i++){
                TreeNode* node= st.front();
                st.pop();
                level.push_back(node->val);
                if(node->left!=NULL) st.push(node->left);
                if(node->right!=NULL) st.push(node->right);

                if(i==size-1) ans.push_back(node->val);
            }
            
        }
        return ans;
    }
};