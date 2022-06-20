//
// Created by 陈某林 on 2022/6/20.
//

#include "mytest_test.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Bitree{
    int num;
    Bitree *Left;
    Bitree *Right;
    Bitree():num(0),Left(nullptr),Right(nullptr){}
    Bitree(int a):num(a),Left(nullptr),Right(nullptr){}
    Bitree(int a,Bitree *left,Bitree *right):num(a),Left(left),Right(right){}
};
Bitree* CreateTree(vector<int> &,vector<int> &);
void LayerPrint(Bitree *);
void preorderPrint(Bitree *);
void inorderPrint(Bitree *);
void backorderPrint(Bitree *);
void mytest_test() {
    vector<int> preorder={1,2,4,7,3,5,6,8};
    vector<int> inorder={4,7,2,1,5,3,8,6};
    Bitree *first = CreateTree(preorder,inorder);
    LayerPrint(first);
    cout<<endl;
    preorderPrint(first);
    cout<<endl;
    inorderPrint(first);
    cout<<endl;
    backorderPrint(first);
    cout<<endl;
}
Bitree* CreateTree(vector<int> &preorder,vector<int> &inorder){
    if(preorder.size()==0)
        return nullptr;
    if(preorder.size()==1){
        Bitree *p = new Bitree(preorder[0]);
        return p;
    }
    int num = preorder[0];
    vector<int> leftpreorder,leftinorder;
    leftinorder.assign(inorder.begin(),find(inorder.begin(),inorder.end(),num));
    inorder.erase(inorder.begin(),inorder.begin()+leftinorder.size()+1);
    preorder.erase(preorder.begin());
    leftpreorder.assign(preorder.begin(),preorder.begin()+leftinorder.size());
    preorder.erase(preorder.begin(),preorder.begin()+leftinorder.size());
    Bitree *p = new Bitree(num,CreateTree(leftpreorder,leftinorder),CreateTree(preorder,inorder));
    return p;
}
void LayerPrint(Bitree *root){
    queue<Bitree*> myqueue;
    myqueue.push(root);
    while(!myqueue.empty()){
        cout<<myqueue.front()->num<<" ";
        if(myqueue.front()->Left)
            myqueue.push(myqueue.front()->Left);
        if(myqueue.front()->Right)
            myqueue.push(myqueue.front()->Right);
        myqueue.pop();
    }
}
void preorderPrint(Bitree *root){
    if(root!= nullptr){
        cout<<root->num<<" ";
        preorderPrint(root->Left);
        preorderPrint(root->Right);
    }
}
void inorderPrint(Bitree *root){
    if(root!= nullptr){
        inorderPrint(root->Left);
        cout<<root->num<<" ";
        inorderPrint(root->Right);
    }
}
void backorderPrint(Bitree *root){
    if(root!= nullptr){
        backorderPrint(root->Left);
        backorderPrint(root->Right);
        cout<<root->num<<" ";
    }
}
