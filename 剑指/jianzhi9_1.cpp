//
// Created by 陈某林 on 2022/6/21.
//

#include "jianzhi9_1.h"
#include <iostream>
#include <queue>
using namespace std;
//双队列实现栈
//左右队列在出栈后进行了互换，为什么呢？
//1、入栈时：通过左队列入队，放置在队列末尾。
//2、出栈时：左队列除最后一个元素，全部移至右队列。最后一个元素作为后进先出的元素，出队列。
//   出栈但
//3、在理论上的出栈以后，左右队列互换，重新回到第1步。
//实际上两个队列其中一个只是中转作用。
void jianzhi9_1() {
    queue<int> *left,*right;
    left = new queue<int>;
    right = new queue<int>;
    int num;
    while(cin>>num){//-1出栈
        if(num!=-1) {//入栈
            left->push(num);
            continue;
        }
        if(!left->empty()){//左队列不为空 可以出栈
            while(left->size()>1){
                right->push(left->front());
                left->pop();
            }
            cout<<"出栈："<<left->front();
            left->pop();
            queue<int> *temp;
            temp = left;
            left = right;
            right = temp;
        }
        else//左队列为空 表明栈内无元素，出错
            cout<<"栈内无元素";
    }
}
