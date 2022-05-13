//合并两个数组A1 A2，两个数组已经进行了排序，将A2中的数据插入到A1中

#include "jianzhi5_1.h"
#include <iostream>
using namespace std;
void jianzhi5_1() {
    int arrA1[20]={3,3,4,7,9};// 1  2  3  4
    int arrA2[20]={0,2,4,5};
    int num1=5,num2=4;
    int end=num1 + num2 - 1;
    int i=num1-1,j=num2-1;
    while(j>=0&&i>=0){
        arrA1[i]>arrA2[j]?arrA1[end--]=arrA1[i--]:arrA1[end--]=arrA2[j--];
    }
    if(arrA1[0]>arrA2[0])
        arrA1[0]=arrA2[0];
    for(int m=0;m<num1+num2;m++){
        cout<<arrA1[m]<<" ";
    }
}
