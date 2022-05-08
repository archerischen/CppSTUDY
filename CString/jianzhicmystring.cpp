//
// Created by 陈某林 on 2022/5/7.
//
#include "jianzhicmystring.h"
#include<iostream>
#include<cstring>
using namespace std;

CMystring::CMystring(const char *pData){
    if(pData== nullptr){
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else{
        m_pData = nullptr;
        int len = strlen(pData);
        m_pData = new char[len+1];
        strcpy(m_pData,pData);
    }
}
CMystring::CMystring(const CMystring &str) {
    m_pData = nullptr;
    int len= strlen(str.m_pData);
    m_pData = new char[len+1];
    strcpy(m_pData,str.m_pData);
}
CMystring& CMystring::operator=(const CMystring &str){
    if(this!=&str){
        this->m_pData = nullptr;
        int len = strlen(str.m_pData);
        m_pData = new char[len+1];
        strcpy(m_pData,str.m_pData);
    }
    return *this;
}
void CMystring::getprint(){
    cout<<this->m_pData<<endl;
}
void jianzhicmystring() {
    //string mystr = "abcdef";
    //const char *pp = mystr.c_str();
    char *pp = "abcde";
    CMystring mys1(pp);
    CMystring mys2 = mys1;
    mys1.getprint();
    mys2.getprint();
    char *pp1 = "zzzzzz";
    CMystring mys3(pp1);
    mys3.getprint();
    mys3 = mys2;
    mys3.getprint();
}
/*
运行结果
abcde
abcde
zzzzzz
abcde*/
