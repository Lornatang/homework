//
// Created by mac on 2018/8/27.
//

#ifndef SHOPMANAGER_CUSTOM_H
#define SHOPMANAGER_CUSTOM_H

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int buyerNum = 0;

// Custom
class custom {
 public:
  custom();
  ~custom();

  string getcustomId() {return customId;}
  string getcustomName() {return customName;}
  string getcustomPasswd() {return customPasswd;}

  void setcustomId(string customId) { customId = customId;}
  void setcustomName(string customName) { customName = customName;}
  void setcustomPasswd(string customPasswd) { customPasswd = customPasswd;}

  static void saveCustom(custom &cs);
  void customCreate(custom &cs);
  static int customEnder(custom &cs, string id, string passwd);
  static void customChange(custom &cs, string id);
  sttaic void customDelete(custom &cs);
  static int getCustom(custom *cs);
  void addMoneyCustom(custom *cs, string id);
  static string *custom_locate(custom &cs, string is);

  custom *next;
  string customId;
  string customName;//姓名
  string customPasswd;//密码
  double money;//账户余额
};
typedef custom *cpoint;//单链表类型，即头指针类型

typedef cpoint clklist;//单链表类型，即头指针类型


#endif //SHOPMANAGER_CUSTOM_H
