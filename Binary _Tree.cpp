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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;  
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) 
        {
            double sum = q.size(), count = 0;  
            for (int i = 0; i < sum; i++)  
            { 
                TreeNode* n = q.front(); 
                q.pop(); 
                count += n->val;
                if (n->left != NULL) 
                    q.push(n->left); 
                if (n->right != NULL) 
                    q.push(n->right); 
            }
            res.push_back(count / sum);
        }
        return res;
    }
};