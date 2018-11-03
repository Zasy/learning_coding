//
// Created by 张哲 on 2018/11/3.

class MyString {
public:
    MyString(const char* s);
    MyString();
    ~MyString();
private:
    char* str;
    int len;
};

//
//MyString& MyString::operator=(const MyString& s){
//    if(this == &s) return *this;
//    data [] str;
//    len = s.len;
//
//    str = new char[s.len + 1];
//    std::strcpy(str, s.str);
//
//    return *this
//}

MyString& MyString::operator=(const MyString& s){
    if(this != &s){
        MyString temp(s);
        char* pTemp = temp.str;
        int lenTemp = temp.len;
        temp.str = str;
        temp.len = len;
        str = pTemp;
        len = lenTemp;
    }
    return *this;
}

