//
// Created by 陈某林 on 2022/5/14.
//

#include "jianzhi7.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode{
    int num;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : num(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : num(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : num(x), left(left), right(right) {}
};
TreeNode* Bildtree(vector<int>&, vector<int>&);
void layerprint(TreeNode*);
void jianzhi7() {
    vector<int> preorder={1,2,4,7,3,5,6,8};
    vector<int> inorder ={4,7,2,1,5,3,8,6};
    TreeNode *base = Bildtree(preorder,inorder);
    layerprint(base);//print in layer order
}
TreeNode* Bildtree(vector<int> &preorder, vector<int> &inorder){
    if(preorder.size()==0)
        return nullptr;
    if(preorder.size()==1){
        TreeNode *p = new TreeNode(preorder[0]);
        return p;
    }
    int a = preorder[0];//now root
    vector<int> leftpreorder,rightinorder;//
    rightinorder.assign(inorder.begin(),find(inorder.begin(),inorder.end(),a));
    inorder.erase(inorder.begin(),find(inorder.begin(),inorder.end(),a)+1);
    //"assign" left is closed && right is open
    preorder.erase(preorder.begin());//remove root
    leftpreorder.assign(preorder.begin(),preorder.begin()+rightinorder.size());
    preorder.erase(preorder.begin(),preorder.begin()+rightinorder.size());
    TreeNode *p = new TreeNode(a, Bildtree(leftpreorder,rightinorder), Bildtree(preorder,inorder));
    return p;
}
void layerprint(TreeNode* node){
    queue<TreeNode*> myqueue;
    myqueue.push(node);
    while(!myqueue.empty()){
        TreeNode* now = myqueue.front();
        if(now != NULL)
        {
            cout<<now->num<<" ";
            if(now->left)
                myqueue.push(now->left);
            //else
                //myqueue.push(NULL);
            if(now->right)
                myqueue.push(now->right);
            //else
                //myqueue.push(NULL);
        }
        else
            cout<<"NULL"<<" ";
        myqueue.pop();
    }
}
