#include <queue>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        
        if (root == NULL) {
            return traversal;
        }
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> level;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = queue.front();
                queue.pop();
                level.push_back(curr->val);
                
                if (curr->left != NULL) {
                    queue.push(curr->left);
                }
                if (curr->right != NULL) {
                    queue.push(curr->right);
                }
            }
            
            traversal.push_back(level);
        }
        
        
        return traversal;
    }
};