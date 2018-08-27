//
// Created by mac on 2018/8/26.
//

#ifndef STUMAGER_CMAINVIEW_H
#define STUMAGER_CMAINVIEW_H

#include "student.h"
#include "stuMager.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

class View {
public:
  View();
  ~View();

  /* 欢迎 */
  void welcome();

  /* 显示菜单 */
  void showMenu();

  /* View 显示所有学生 */
  void showAllStuAtView(const map<int, Student> &stu_m1);

  /* View层 添加一个学生 */
  void addStuAtView(map<int, Student> &stu_m1);

  /* View 查找一个学生 */
  void findStuAtView(const map<int, Student> &m1);

  /* View层删除一个学生 */
  void deleteByIdAtView(map<int, Student> &v1);

  /* View层 更新一个学生 */
  void updateByIdAtView(map<int, Student> &m1);

  /* view层 把map保存进文件 */
  void saveToFileAtView(const map<int, Student> &m1, string pathName);

  /* View层 把文件中的东西导入 map */
  void readFromFileAtView(map<int, Student> &m, string pathName);
};

#endif // STUMAGER_CMAINVIEW_H
