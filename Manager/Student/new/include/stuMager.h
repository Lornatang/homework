//
// Created by mac on 2018/8/26.
//

#ifndef STUMAGER_CSTUDENTMAGER_H
#define STUMAGER_CSTUDENTMAGER_H

#include "Student.h"
#include <map>
#include <string>

class stuMager {
public:
  stuMager();
  ~stuMager();

  // 增
  Student addAStu(std::map<int, Student> &m1, Student &stu);

  // 删
  bool deleteStuById(std::map<int, Student> &m1, const int &id);

  // 改
  Student updateStu(std::map<int, Student> &m1, const Student &stu);

  // 查 by id
  Student findById(const std::map<int, Student> &m1, const int &id) const;

  // showAll
  void showAll(const std::map<int, Student> &m1) const;

  // save to file
  bool saveToFile(const std::map<int, Student> &m1,
                  const std::string &pathName) const;

  // read from file
  bool readFromFile(std::map<int, Student> &m1, std::string path);

private:
};

#endif // STUMAGER_CSTUDENTMAGER_H
