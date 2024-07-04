#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        if (root == nullptr) return res;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        findParent(parentMap, root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (K == 0) {
                    res.push_back(curr->val);
                }
                if (parentMap.count(curr) && !visited.count(parentMap[curr])) {
                    q.push(parentMap[curr]);
                    visited.insert(parentMap[curr]);
                }
                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
            }
            K--;
            if (K < 0) break;
        }

        return res;
    }

private:
    void findParent(unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            parentMap[root->left] = root;
            findParent(parentMap, root->left);
        }
        if (root->right != nullptr) {
            parentMap[root->right] = root;
            findParent(parentMap, root->right);
        }
    }
};
