//
// Created by zhanGGe on 2018/9/6.
// 从尾到头打印链表
// 使用递归的方式将链表打印 利用递归模仿堆栈的特性
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

void PrintList(ListNode* head){
    if(head->next != NULL) {
        PrintList(head->next);
    }
    cout << head->val << endl;
}

