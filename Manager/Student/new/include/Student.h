//
// Created by mac on 2018/8/26.
//

#ifndef STUMAGER_CSTUDENT_H
#define STUMAGER_CSTUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student
{
    /* friend function */
    friend ostream &operator << (ostream &os, Student &stu);
    friend istream &operator >> (istream &is, Student &stu);

public:

    Student();
    ~Student();

    int getId() const;
    void setId(int val);

    string getName() const;
    void setName(string val);

    int getAge() const;
    void setAge(int val);


private:

    int id;
    string name;
    int age;

};

#endif //STUMAGER_CSTUDENT_H
