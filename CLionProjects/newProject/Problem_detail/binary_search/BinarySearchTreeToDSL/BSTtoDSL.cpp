//
// Created by zhanGGe on 2018/9/13.
// 二叉搜索树转化为双向链表

 //Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct DoubleLinkList {
    int val;
    DoubleLinkList *last;
    DoubleLinkList *next;
    DoubleLinkLIst(int x) : val(x), last(NULL), right(NULL) {}
};



void ConvertNode(TreeNode* head){
    DoubleLinkList* head =NULL;
    DoubleLinkList* p = DoubleLinkList(head->val);
    DoubleLinkList* tail_1;
    DoubleLinkList* head_2;


}

void ConvertNodeToList(TreeNode* n, DoubleLinkList* &head, DoubleLinkList* &tail){
    DoubleLinkList* p = new DoubleLinkList(n->val);
    DoubleLinkList* head_l, tail_l, head_r, tail_r;
    if (n->left == nullptr && n->right == nullptr){
        head = p;
        tail = p;
        return;
    }

    if (n->left == nullptr){
        head = p;
        ConvertNodeToList(n->right, head_r, tail_r);
        p->next = head_r;
        head_r->last = p;
        tail = tail_r;
        return;
    }

    if (n->right == nullptr){
        tail = p;
        ConvertNodeToList(n->left, head_l, tail_l);
        p->last = tail_l;
        tail_l->next = p;
        head = head_l;
        return;
    }
    ConvertNodeToList(n->left, head_l, tail_l);
    ConvertNodeToList(n->right, head_r, tail_r);

    p->last = tail_l;
    p->next = head_r;

    head = head_l;
    tail = tail_r;
}


