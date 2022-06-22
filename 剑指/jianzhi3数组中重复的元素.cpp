//
// Created by 陈某林 on 2022/6/22.
//
#include <vector>
#include <iostream>
using namespace std;
void jianzhi3() {
    int num,now;
    cin>>num;
    vector<int> myarr;
    for(int i=0;i<num;i++){
        cin>>now;
        myarr.push_back(now);
    }
    //思路：由于0-num中每个数字都有可能存在多个
    //查找0号脚标的数据时，查看其所存数字的脚标下的数字
    //若一致则表示重复 可打印输出
    //不一致则更换为 所存数字为脚标下所存的数字
    for(int i=0;i<num;i++){
        bool flag = false;
        //直到0号脚标下找到0 若没有找到0证明存在重复元素
        //则下面继续交换即可
        while(myarr[i]!=i){
            if(myarr[i]==myarr[myarr[i]]){
                cout<<myarr[i]<<endl;
                flag = true;
                break;
            }
            int temp=myarr[i];
            myarr[i]=myarr[myarr[i]];
            myarr[temp]=temp;
        }
        if(flag)//找到就退出
            break;
    }
    //下方为测试用
    cout<<endl;
    for(int i:myarr)
        cout<<i<<" ";
}
