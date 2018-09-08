//
// Created by zhanGGe on 2018/9/8.
// 二叉树的后序遍历 递归和非递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 后序递归
struct StNode{
    TreeNode* node;
    int TimesPop;

    StNode(TreeNode* N= NULL):node(N), TimesPop(0){}
};

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        // stack<StNode> s;
        // StNode cur(root);
        // s.push(cur);
        // vector<int> res;
        // while(!s.empty()){
        //     StNode cur;
        //     cur.node = s.top().node;
        //     cur.TimesPop = s.top().TimesPop;
        //     s.pop();
        //     if(++cur.TimesPop == 3){
        //         res.push_back(cur.node->val);
        //     }
        //     if(++cur.TimesPop == 1){
        //         s.push(cur);
        //         if(cur.node->left != NULL) s.push(StNode(cur.node->left));
        //     }else{
        //         s.push(cur);
        //         if(cur.node->left != NULL) s.push(StNode(cur.node->right));
        //     }
        // }
        // return res;

        if (!root) return vector<int> {};

        vector<int> result;
        postTraversal(root, result);

        return result;


    }


    void postTraversal(TreeNode* root, vector<int> &result) {
        if(root->left)  postTraversal(root->left, result);
        if(root->right) postTraversal(root->right, result);

        result.push_back(root->val);
    }
};

// 后序非递归
vector<int> postorderTraversal(TreeNode* root) {
    // stack<StNode> s;
    // StNode cur(root);
    // s.push(cur);
    // vector<int> res;
    // while(!s.empty()){
    //     StNode cur;
    //     cur.node = s.top().node;
    //     cur.TimesPop = s.top().TimesPop;
    //     s.pop();
    //     if(++cur.TimesPop == 3){
    //         res.push_back(cur.node->val);
    //     }
    //     if(++cur.TimesPop == 1){
    //         s.push(cur);
    //         if(cur.node->left != NULL) s.push(StNode(cur.node->left));
    //     }else{
    //         s.push(cur);
    //         if(cur.node->left != NULL) s.push(StNode(cur.node->right));
    //     }
    // }
    // return res;
    if(!root) return vector<int>{};

    stack<TreeNode*> s;
    s.push(root);
    vector<int> result;
    TreeNode* p = nullptr;
    while(!s.empty()){
        p = s.top();
        s.pop();
        result.insert(result.begin(), p->val);
        if(p->left)  s.push(p->left);
        if(p->right) s.push(p->right);
    }

    return result;
}




