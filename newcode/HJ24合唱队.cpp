#include<iostream>
using namespace std;
void creat(int *&p,int *&dp1,int *&dp2,int num){
    p = new int[num];
    dp1 = new int[num];
    dp2 = new int[num];
    for(int i=0;i<num;i++){
        cin>>p[i];
        dp1[i]=0;
        dp2[i]=0;
    }
}
int main(){
    int num;
    cin >> num;
    int *p = nullptr;
    int *dp1 = nullptr;
    int *dp2 = nullptr;
    creat(p, dp1 , dp2, num);
    
    for(int i=0;i<num;i++){
         for(int j=0;j<i;j++){
            if(p[i]>p[j])
                dp1[i] = max(dp1[j]+1,dp1[i]);
         }
    }
    for(int i=num-1;i>=0;i--){
         for(int j=num-1;j>i;j--){
            if(p[i]>p[j])
                dp2[i] = max(dp2[j]+1,dp2[i]);
         }
    }
    int max=0;
    for(int i=0;i<num;i++){
        if(dp1[i]+dp2[i]>max)
            max=dp1[i]+dp2[i];
    }
    cout<<num-max-1;
}
