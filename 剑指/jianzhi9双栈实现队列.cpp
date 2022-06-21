#include "jianzhi9.h"
#include <iostream>
#include <stack>
using namespace std;
//思路：左栈作输入，右栈作输出
//输入时：左栈入栈
//输出时：若右栈为空，左栈非空，则将左栈元素依次出栈压入右栈，实现反转。
//输出时：若左右栈均为空，输出“栈为空”。
void jianzhi9() {
    stack<int> left,right;
    int num;
    while(cin>>num) {//-1 出队列
        if(num!=-1){
            left.push(num);
            continue;
        }
        if(right.size()==0){
            if(left.size()==0) {
                cout << "队列为空" << endl;
                continue;
            }
            while(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        cout<<right.top();
        right.pop();
    }
}
