//
// Created by zhanGGe on 2018/9/8.
// 二叉树的中序遍历 递归和非递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归版本
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return vector<int>{};

        inTraversal(result, root);

        return result;
    }


    vector<int> inorderTraversalWithRecrusive(TreeNode* root) {
        vector<int> result;
        TreeNode* p = root;
        stack<TreeNode*> s;

        while(p || !s.empty()) {
            if(p){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p ->right;
            }
        }

        return result;
    }


    void inTraversal(vector<int> &result, TreeNode* root) {
        if(root->left) inTraversal(result, root->left);
        result.push_back(root->val);
        if(root->right) inTraversal(result, root->right);
    }
};


