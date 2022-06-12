// 3  3个人
// 0  0为降序排序
// fang 90  名字 与 分数
// yang 50
// ning 70

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Peop{
    string name;
    int score;
};
bool cmp_up(Peop p1,Peop p2);
bool cmp_down(Peop p1,Peop p2);
int main(){
    int num,method;
    vector<Peop> myv;
    cin>>num>>method;
    for(int i=0;i<num;i++){
        Peop peop;
        cin>>peop.name>>peop.score;
        myv.push_back(peop);
    }
    if(method==1)//升序
        stable_sort(myv.begin(),myv.end(),cmp_up);
    else
        stable_sort(myv.begin(),myv.end(),cmp_down);
    for(auto it=myv.begin();it!=myv.end();it++)
        cout<<(*it).name<<" "<<(*it).score<<endl;
}
bool cmp_up(Peop p1,Peop p2){//升序
    return p1.score<p2.score;
}
bool cmp_down(Peop p1,Peop p2){//降序
    return p1.score>p2.score;
}
