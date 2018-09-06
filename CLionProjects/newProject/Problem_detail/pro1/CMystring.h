//
// Created by zhanGGe on 2018/9/4.
//

#ifndef LEARNING_OFFER_CMYSTRING_H
#define LEARNING_OFFER_CMYSTRING_H
class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

private:
    char* m_pData;
};
#endif //LEARNING_OFFER_CMYSTRING_H


