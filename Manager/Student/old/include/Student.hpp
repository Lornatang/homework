//
// Created by mac on 2018/8/26.
//

#ifndef STUDENT_MANAGER_STUDET_H
#define STUDENT_MANAGER_STUDET_H

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
  ~Student();            //析构函数
  void InputStudent();   //输入学生信息
  void OutputStudent();  //输出学生信息
  void DeleteStudent();  //删除学生信息
  void SearchStudent();  //查找学生信息
  void ChangeStudent();  //修改学生信息
  void ScortByChinese(); //对学生的语文成绩排序
  void ScortByMath();    //对学生的数学成绩排序
  void ScortByEnglish(); //对学生的英语成绩排序
  void ScortByTotal();   //对学生的总分排序

private:
  Student *St;    //学生类指针
  int Size;       //学生的人数
  string Name;    //姓名
  int Age;        //年龄
  int No;         //学号
  float Score[3]; //三科的成绩
  float Total;    //总分
  float Ave;      //平均分
};

#endif // STUDENT_MANAGER_STUDET_H
