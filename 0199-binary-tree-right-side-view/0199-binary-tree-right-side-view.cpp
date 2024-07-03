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
        queue<TreeNode*> q;
        if(root==nullptr) return{};
         vector<int>ans;
        q.push(root);
        TreeNode* node=NULL;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                node=q.front();
                q.pop();
                if(node->left!=nullptr)
                  q.push(node->left);
                if(node->right!=NULL)
                  q.push(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};