//
// Created by 张哲 on 2018/11/8.
//

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v){
        val = v;
    }
};


int depthBinaryTree(TreeNode* root, int & max){
    if( root == nullptr){
        return 0;
    }

    int l = depthBinaryTree(root->left);
    int r = depthBinaryTree(root->right);

    max = (l + r + 1) > max ? l + r + 1 : max;
    return (l > r) ? l + 1 : r + 1;
}

