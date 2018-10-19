//
// Created by zhanGGe on 2018/9/18.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
const int maxn=1024;
int inOrder[maxn];
struct node {
    int v;
    node *l, *r;
    node(int val=0) : v(val), l(nullptr), r(nullptr) {}
};
node* BuildTree(vector<int> layer, int inL, int inR) {
    if(layer.size() == 0)   {   return nullptr;  }
    node* root=new node(layer[0]);
    int k;
    for(k=inL; k <= inR; k++)  {
        if(layer[0] == inOrder[k])   {    break;    }
    }
    vector<int> leftLayer;
    vector<int> rightLayer;
    for(int i=1; i < layer.size(); i++)   {
        bool isLeft=false;
        for(int j=inL; j < k; j++)   {
            if(layer[i] == inOrder[j])    {
                isLeft=true;
                break;
            }
        }
        if(isLeft)   {
            leftLayer.push_back(layer[i]);
        }   else   {
            rightLayer.push_back(layer[i]);
        }
    }
    root->l=BuildTree(leftLayer, inL, k - 1);
    root->r=BuildTree(rightLayer, k + 1, inR);
    return root;
}
void PreOrderLeaf(node * root) {
    if(root == nullptr) return;
    if(root->l==nullptr && root->r==nullptr) cout << root->v << ' ';  PreOrderLeaf(root->l);
    PreOrderLeaf(root->r);
}
void PreOrder(node * root) {
    if(root == nullptr) return;
    cout << root->v << ' ';
    PreOrder(root->l);
    PreOrder(root->r);
}
void PostOrder(node *root) {
    if(root == nullptr) return;
    PostOrder(root->l);
    PostOrder(root->r);
    cout << root->v <<' ';
}


void DelTree(node *root) {
    if(root == nullptr) return;
    DelTree(root->l);
    DelTree(root->r);
    delete root;
}


int main() {
    string pre, in;
    getline(cin, pre);
    getline(cin, in);
    stringstream spliter(pre);

    int lenPre=0;
    vector<int> layer;
    while(spliter.good())  {
        int i;
        spliter>>i;
        layer.push_back(i);
    }

    int lenIn=0;
    spliter.clear();
    spliter.str(in);

    while(spliter.good())  {   spliter>>inOrder[lenIn++];  }

    node *tmpRoot=BuildTree(layer, 0, lenIn-1);

    PreOrderLeaf(tmpRoot);  cout<<endl;  PreOrder(tmpRoot);
    cout<<endl;

    PostOrder(tmpRoot);

    cout<<endl;
    return 0;
}