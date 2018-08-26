#include <iostream>
#include <string>
#include "../include/Student.h"
using namespace std;

// 学生默认id是-1，说明这暂时是一个无效的学生。
Student::Student() {this->id = -1;}
Student::~Student() {}


int Student::getId() const { return id; }
void Student:: setId(int val) { id = val; }

string Student:: getName() const { return name; }
void Student:: setName(string val) { name = val; }


int Student:: getAge() const { return age; }
void Student:: setAge(int val) { age = val; }


ostream & operator<<(ostream & os, Student & stu) {
    os<<stu.getId()<<"     "<<stu.getName()<<"     "<<stu.getAge();
    return os;
}

istream & operator>>(istream & is, Student & stu) {
    is>>stu.id>>stu.name>>stu.age;
    return is;
}
