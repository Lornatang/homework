//
// Created by mac on 2018/8/26.
//

#ifndef ADRESS_BOOK_PERSON_H
#define ADRESS_BOOK_PERSON_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class person
{
private:
    int id;
    string name;
    string tel;
    string addr;
public:
    person();
    ~person();
    static int count; //记录通讯录中的人数
    int GetId();
    void SetName();
    string GetName() const;
    void SetTel();
    string GetTel() const;
    void SetAddr();
    string GetAddr() const;
    void choose();
    void insert();
    void show();
    void search();
    void interface();
    void delete_info();
    void exit_info();
    void modify();
};

#endif //ADRESS_BOOK_PERSON_H
