//
// Created by 陈某林 on 2022/5/8.
//
//在一个n*m的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include "jianzhi4.h"
#include <iostream>
using namespace std;
bool find(int* arr,int,int,int);
void jianzhi4() {
    int arr[4][4]={1,2,8,9,
                   2,4,9,12,
                   4,7,10,13,
                   6,8,11,15};
    int rows=4,cols=4,mfind=6;
    int a = find(*arr,rows,cols,mfind);
    cout<<a;
}
bool find(int *arr,int rows,int cols,int mfind){
    int row = 0;
    int col = cols-1;
    while(row<rows&&col>=0){
        cout<<arr[row*cols+col];
        if(arr[row*cols+col]==mfind)
            return true;
        else if(arr[row*cols+col]>mfind)
                col--;
        else row++;
    }
    return false;
}
