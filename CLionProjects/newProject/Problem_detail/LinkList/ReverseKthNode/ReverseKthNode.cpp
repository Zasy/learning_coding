//
// Created by zhanGGe on 2018/9/6.
// 倒数第k个结点 链表长度大于k


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* ReveseKthNode(ListNode* head, int k) {
    int count = 0;
    ListNode* p,q = head;
    while(count == k) {
        p = p->next;
    }

    while(p){
        p = p->next;
        q = q->next;
    }

    return q;
}

