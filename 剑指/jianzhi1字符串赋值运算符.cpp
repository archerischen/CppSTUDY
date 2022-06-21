// .h
// Created by 陈某林 on 2022/6/21.
//
class CMyString {
public:
    CMyString(const char *mData = nullptr);
    CMyString(const CMyString& str);
    CMyString & operator=(const CMyString &str);
    void myprint();
    ~CMyString(){
        if(m_pData== nullptr)
            delete [] m_pData;
    }
private:
    char *m_pData;
};
void jianzhi1();

//CPP
// Created by 陈某林 on 2022/6/21.
//
#include "jianzhi1.h"
#include <cstring>
#include <iostream>
using namespace std;
CMyString::CMyString(const char *mData) {
//    this->m_pData = mData;
    if(mData == nullptr){
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else{
        this->m_pData = nullptr;
        int len = strlen(mData);
        this->m_pData = new char[len+1];
        strcpy(this->m_pData,mData);
    }
}
CMyString::CMyString(const CMyString &str) {
    this->m_pData = nullptr;
    int len = strlen(str.m_pData);
    this->m_pData = new char[len+1];
    strcpy(this->m_pData,str.m_pData);
}
CMyString& CMyString::operator=(const CMyString &str) {
    delete[] m_pData;
    this->m_pData = nullptr;
    int len = strlen(str.m_pData);
    this->m_pData = new char[len+1];
    strcpy(m_pData,str.m_pData);
    return *this;
}
void CMyString::myprint() {
    cout<<this->m_pData<<endl;
}
void jianzhi1(){
    char *p =(char *)"abcdef";
    CMyString str1(p);
    str1.myprint();
    CMyString str2(str1);
    str2.myprint();
    CMyString str3((char *)"123");
    str3 = str2 = str3;
    str3.myprint();
}
//输出
//abcdef
//abcdef
//123
