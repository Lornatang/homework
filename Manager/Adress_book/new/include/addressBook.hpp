//
// Created by mac on 2018/8/26.
//

#ifndef NEW_ADDRESSBOOK_H
#define NEW_ADDRESSBOOK_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int Enterflag = 0; //定义输入次数的全局变量

class person {
protected:
  int firstname;     //学号前缀
  int Num;           //学号
  char name[40];     //姓名
  char sex[10];      //性别
  int age;           //年龄
  char tel[20];      //电话
  char email[60];    //邮箱
  char postcode[10]; //邮编
  char IDnumber[30]; //身份证号
  person *mynext;    //下一个学生指针
public:
  person();
  person(int pNum, int pfirstname, char pname[], char psex[], int page,
         char ptel[], char pemail[], char ppostcode[], char pIDnumber[]);
  person(int pNum, int pfirstname, char pname[], char psex[], int page,
         char ptel[], char pemail[], char ppostcode[], char pIDnumber[],
         person *next);
  int getfirstname();
  int getNum();
  char *getname();
  char *getsex();
  int getage();
  void getage(int ag);
  char *gettel();
  char *getemail();
  char *getpostcode();
  char *getIDnumber();
  person *getnext();
  void setnext(person *next);
  void output();
};

class AddressBook {
private:
  person *myfirst; //指向联系人人员的指针
public:
  AddressBook();
  AddressBook(int npNum, int firstname, char npname[], char npsex[], int npage,
              char nptel[], char npemail[], char nppostcode[],
              char npIDnumber[]);
  ~AddressBook();

  void displayRecord(); //显示记录
  bool queryRecord();   //查询记录
  bool queryRecord(int firstname, int fNum);
  //有参查询函数，学号查询
  void addRecord();                      //添加或新建记录
  void input(int number, int firstname); //键盘读入新成员信息、
  void insert(int npNum, int firstname, char npname[], char npsex[], int npage,
              char nptel[], char npemail[], char nppostcode[],
              char npIDnumber[]);
  //成员链表插入新成员信息
  bool update();       //修改记录
  bool removeRecord(); //删除记录
  void saveRecords();  //保存记录
  void loadRecords();  //读取记录
  void clear();        //清空当前通讯录
};

person::person() {
  Num = 0;
  firstname = 0;
  strcpy(name, "");
  strcpy(sex, "");
  age = 0;
  strcpy(tel, "");
  strcpy(email, "");
  strcpy(postcode, "");
  strcpy(IDnumber, "");
  mynext = NULL;
}
person::person(int pNum, int pfirstname, char pname[], char psex[], int page,
               char ptel[], char pemail[], char ppostcode[], char pIDnumber[]) {
  Num = pNum;
  firstname = pfirstname;
  strcpy(name, pname);
  strcpy(sex, psex);
  age = page;
  strcpy(tel, ptel);
  strcpy(email, pemail);
  strcpy(postcode, ppostcode);
  strcpy(IDnumber, pIDnumber);
  mynext = NULL;
}
person::person(int pNum, int pfirstname, char pname[], char psex[], int page,
               char ptel[], char pemail[], char ppostcode[], char pIDnumber[],
               person *next) {
  Num = pNum;
  firstname = pfirstname;
  strcpy(name, pname);
  strcpy(sex, psex);
  age = page;
  strcpy(tel, ptel);
  strcpy(email, pemail);
  strcpy(postcode, ppostcode);
  strcpy(IDnumber, pIDnumber);
  mynext = next;
}
int person::getNum() { return Num; }
int person::getfirstname() { return firstname; }
char *person::getname() { return name; }
char *person::getsex() { return sex; }
int person::getage() { return age; }
void person::getage(int ag) { age = ag; }
char *person::gettel() { return tel; }
char *person::getemail() { return email; }
char *person::getpostcode() { return postcode; }
char *person::getIDnumber() { return IDnumber; }
person *person::getnext() { return mynext; }
void person::setnext(person *next) { mynext = next; }
void person::output() {
  cout << "--------------------------------------------------------------------"
          "------------------------------------------------"
       << endl;
  cout << setw(12) << "学号" << setw(20) << "姓名" << setw(9) << "性别"
       << setw(8) << "年龄";
  cout << setw(8) << "电话" << setw(22) << "邮箱" << setw(16) << "邮编"
       << setw(12) << "身份证号" << endl;
  cout << "--------------------------------------------------------------------"
          "------------------------------------------------"
       << endl;
  cout << setw(14) << firstname << setw(4) << Num << setw(15) << name << setw(7)
       << sex << setw(8) << age;
  cout << setw(13) << tel << setw(26) << email << setw(8) << postcode
       << setw(20) << IDnumber << endl;
  cout << "--------------------------------------------------------------------"
          "------------------------------------------------"
       << endl;
}
#endif // NEW_ADDRESSBOOK_H
