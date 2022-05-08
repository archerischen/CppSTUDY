//
// Created by ³ÂÄ³ÁÖ on 2022/5/7.
//

#ifndef TESTALL_JIANZHICMYSTRING_H
#define TESTALL_JIANZHICMYSTRING_H

class CMystring{
public:
    CMystring(const char *pData = nullptr);
    CMystring(const CMystring &str);
    CMystring& operator=(const CMystring &str);
    ~CMystring(){
        if(m_pData!= nullptr)
            delete[] m_pData;
    }
    void getprint();
private:
    char* m_pData;
};
void jianzhicmystring();

#endif //TESTALL_JIANZHICMYSTRING_H
