//
// Created by mac on 2018/8/26.
//

#include "../include/addressBook.hpp"

AddressBook::AddressBook() { myfirst = NULL; }

AddressBook::AddressBook(int npNum, int npfirstname, char npname[],
                         char npsex[], int npage, char nptel[], char npemail[],
                         char nppostcode[], char npIDnumber[]) {
  myfirst = new person(npNum, npfirstname, npname, npsex, npage, nptel, npemail,
                       nppostcode, npIDnumber);
}
AddressBook::~AddressBook() {
  person *next = myfirst, *temp;
  while (next != NULL) {
    temp = next;
    next = next->getnext();
    delete temp;
  }
  myfirst = NULL;
}
//添加或新建记录
void AddressBook::addRecord() {
  int tempnum, tempfirstname, number1, number2;
  char flag[5];
  person *per = myfirst;
  if (per == NULL) {
    cout << "目前没有学生通讯录信息，请键盘输入添加(Y)或直接返回程序主菜单(N):";
    cin >> flag;
    while (1) {
      if (strcmp(flag, "Y\0") == 0) {
        while (1) {
          cout << "请输入学生的学号前缀：";
          cin >> tempfirstname;
          if (tempfirstname < 0) {
            cout << "输入错误，请重新输入!";
            continue;
          }
          break;
        }
        while (1) {
          cout << "请输入学生的尾号后4位:";
          cin >> tempnum;
          if (tempnum < 1000 || tempnum > 9999) {
            cout << "输入错误，请重新输入!";
            continue;
          } else {
            input(tempnum, tempfirstname);
            cout << "是否继续添加(Y/N):";
            cin >> flag;
            if ((strcmp(flag, "N\0") == 0))
              return;
            addRecord();
          }
        }
      } else if ((strcmp(flag, "N\0") == 0)) {
        Enterflag = 0;
        return;
      } else {
        cout << "输入错误,请键盘输入添加(Y)或直接返回程序主菜单(N):";
        cin >> flag;
        continue;
      }
    }
  } else {
    cout << "目前已有的学生信息:" << endl;
    displayRecord();
    cout << "学号前缀是否与最后一个同学相同?(Y/N):";
    cin >> flag;
    while (1) {
      if (strcmp(flag, "N\0") == 0) {
        while (strcmp(flag, "N\0") == 0) {
          cout << "请输入学生的学号前缀：";
          cin >> tempfirstname;
          if (tempfirstname < 0) {
            cout << "输入错误，请重新输入!";
            continue;
          }
          break;
        }
        while (strcmp(flag, "N\0") == 0) {
          cout << "请输入学生的尾号后4位:";
          cin >> tempnum;
          if (tempnum < 1000 || tempnum > 9999) {
            cout << "输入错误，请重新输入!";
            continue;
          }
          input(tempnum, tempfirstname);
          break;
        }
        break;
      } else if (strcmp(flag, "Y\0") == 0) {
        while (strcmp(flag, "Y\0") == 0) {
          cout << "请输入学生的尾号后4位:";
          cin >> tempnum;
          if (tempnum < 1000 || tempnum > 9999) {
            cout << "输入错误，请重新输入!";
            continue;
          }
          break;
        }
        if (per->getnext() == NULL) {
          number1 = per->getfirstname();
          input(tempnum, number1);
        } else {
          while (per->getnext() != NULL)
            per = per->getnext();
          number2 = per->getfirstname();
          input(tempnum, number2);
        }
      }
      break;
    }
  }
}
//显示记录
void AddressBook::displayRecord() {
  person *head = myfirst;
  cout << "--------------------------------------------------------------------"
          "------------------------------------------------"
       << endl;
  cout << setw(12) << "学号" << setw(20) << "姓名" << setw(9) << "性别"
       << setw(8) << "年龄";
  cout << setw(8) << "电话" << setw(22) << "邮箱" << setw(16) << "邮编"
       << setw(12) << "身份证号" << endl;
  int i = 0;
  while (head != NULL) {
    i++;
    cout << "------------------------------------------------------------------"
            "--------------------------------------------------"
         << endl;
    cout << setw(14) << head->getfirstname() << setw(4) << head->getNum()
         << setw(15) << head->getname() << setw(7) << head->getsex() << setw(8)
         << head->getage();
    cout << setw(13) << head->gettel() << setw(26) << head->getemail()
         << setw(8) << head->getpostcode() << setw(20) << head->getIDnumber()
         << endl;
    head = head->getnext();
  }
  cout << "--------------------------------------------------------------------"
          "------------------------------------------------"
       << endl;
  cout << "目前总共有" << i << "个学生数据" << endl;
}
//清空当前通讯录
void AddressBook::clear() {
  person *head = myfirst;
  person *fhead = head;
  ofstream fout("addressbook.txt", ios::trunc);
  while (head != NULL) {
    fhead = head->getnext();
    delete head;
    head = fhead;
  }
  myfirst = NULL;
  fout.close();
  cout << "数据清除完毕!\n";
}

//查询记录，有参，学号
bool AddressBook::queryRecord(int stufirstid, int foNum) {
  person *head = myfirst;
  person *fhead = head;
  while (head != NULL) {

    if (head->getfirstname() == stufirstid && head->getNum() == foNum) {
      head->output();
      return true;
    } else {
      fhead = head;
      head = head->getnext();
    }
  }
  return false;
}
//查询记录，无参
bool AddressBook::queryRecord() {
  int stuid, stufirstid, k;
  char stustr[60];
  person *head = myfirst;
  person *fhead = head;
  while (1) {
    cout << "请确定使用何种方法查找学生信息.\n1.姓名 2.学号:";
    cin >> k;
    if (k != 1 && k != 2) {
      cout << "输入错误，请重新输入!";
      continue;
    }
    switch (k) {
    case 1: {
      cout << "请输入学生的姓名:";
      cin >> stustr;
      if (head == NULL) {
        cout << "本校暂无学生信息!" << endl;
        return false;
      } else {
        while (head != NULL) {
          if (strcmp(head->getname(), stustr) == 0) {
            head->output();
            if (head->getnext() == NULL)
              return true;
          }
          fhead = head;
          head = head->getnext();
        }
        cout << "本校无此学生信息!" << endl;
        return false;
      }
    } break;
    case 2: {
      cout << "请输入学生的学号前缀:";
      cin >> stufirstid;
      cout << "请输入学生的学号尾号后4位:";
      cin >> stuid;
      if (head == NULL) {
        cout << "本校暂无学生信息!" << endl;
        return false;
      } else {
        while (head != NULL) {
          if (head->getfirstname() == stufirstid && head->getNum() == stuid) {
            head->output();
            return true;
          } else {
            fhead = head;
            head = head->getnext();
          }
        }
        cout << "本校无此学生信息!" << endl;
        return false;
      }
    } break;
    }
  }
}
//键盘读入新成员信息、
void AddressBook::input(int number, int firstname) {
  int page;
  char pname[40], psex[10], ptel[20], pemail[60], ppostcode[10], pIDnumber[30];
  cout << "请输入学号为" << firstname << number << "的信息:" << endl;
  cout << "姓名:";
  cin >> pname;
  cout << "性别:";
  cin >> psex;
  cout << "年龄:";
  cin >> page;
  cout << "电话号码:";
  cin >> ptel;
  cout << "邮箱:";
  cin >> pemail;
  cout << "邮编:";
  cin >> ppostcode;
  cout << "身份证号:";
  cin >> pIDnumber;
  insert(number, firstname, pname, psex, page, ptel, pemail, ppostcode,
         pIDnumber);
}
//成员链表插入新成员信息
void AddressBook::insert(int npNum, int npfirstname, char npname[],
                         char npsex[], int npage, char nptel[], char npemail[],
                         char nppostcode[], char npIDnumber[]) {
  person *pers = myfirst;
  if (pers == NULL)
    myfirst = new person(npNum, npfirstname, npname, npsex, npage, nptel,
                         npemail, nppostcode, npIDnumber);
  else {
    while (pers->getnext() != NULL)
      pers = pers->getnext();
    pers->setnext(new person(npNum, npfirstname, npname, npsex, npage, nptel,
                             npemail, nppostcode, npIDnumber, pers->getnext()));
  }
}
//修改记录
bool AddressBook::update() {
  int number, number2;
  char flag[5];
  person *head = myfirst;
  person *fhead = head;
  cout << "请输入要修改的学生学号前缀:";
  cin >> number;
  cout << "请输入要修改的学生学号尾号后4位:";
  cin >> number2;
  if (head == NULL) {
    cout << "本校目前没有学生!" << endl;
    return false;
  } else
    while (head != NULL) {
      if (head->getfirstname() == number && head->getNum() == number2) {
        cout << "您要修改的学生信息如下:" << endl;
        head->output();
        while (1) {
          int i;
          float newnumber;
          char newtxt[60];
          cout << "请输入要修改的信息项，“.”提示输入:";
          cout << "1.姓名 2.性别 3.年龄 4.电话 5.邮箱 6.邮编 7.身份证号\n";
          cout << ".";
          cin >> i;
          switch (i) {
          case 1: {
            cout << "请输入学生姓名:\n";
            cout << ".";
            cin >> newtxt;
            strcpy(head->getname(), newtxt);
            queryRecord(number, number2);
          } break;
          case 2: {
            cout << "请输入学生性别:\n";
            cout << ".";
            cin >> newtxt;
            strcpy(head->getsex(), newtxt);
            queryRecord(number, number2);
          } break;
          case 3: {
            cout << "请输入学生年龄:\n";
            cout << ".";
            cin >> newnumber;
            head->getage(newnumber);
            queryRecord(number, number2);
          } break;
          case 4: {
            cout << "请输入学生新的电话:\n";
            cout << ".";
            cin >> newtxt;
            strcpy(head->gettel(), newtxt);
            queryRecord(number, number2);
          } break;
          case 5: {
            cout << "请输入学生新的邮箱:\n";
            cout << ".";
            cin >> newtxt;
            strcpy(head->getemail(), newtxt);
            queryRecord(number, number2);
          } break;
          case 6: {
            cout << "请输入学生新的邮编:\n";
            cout << ".";
            cin >> newtxt;
            strcpy(head->getpostcode(), newtxt);
            queryRecord(number, number2);
          } break;
          case 7: {
            cout << "请输入学生正确的身份证号:\n";
            cout << ".";
            cin >> newtxt;
            strcpy(head->getIDnumber(), newtxt);
            queryRecord(number, number2);
          } break;
          default:
            return false;
          }
          cout << "是否继续修改(Y/N):";
          cin >> flag;
          if (strcmp(flag, "Y\0") == 0)
            continue;
          else {
            return true;
          }
        }
      } else {
        head = head->getnext();
        fhead = head;
      }
    }
  cout << "本校没有这样一个学生!" << endl;
  return false;
}
//删除记录
bool AddressBook::removeRecord() {
  int stuid, stufirstid;
  person *head = myfirst;
  person *fhead = head;
  cout << "请输入学生的学号前缀:";
  cin >> stufirstid;
  cout << "请输入学生的学号尾号后4位:";
  cin >> stuid;
  if (head == NULL) {
    cout << "错误!无学生可以删除!" << endl;
    return false;
  } else if (head->getfirstname() == stufirstid && head->getNum() == stuid) {
    myfirst = myfirst->getnext();
    cout << "学号为" << stufirstid << stuid << "的学生被删除成功!" << endl;
    delete head;
    return true;
  } else {
    head = head->getnext();
    while (head != NULL) {
      if (head->getfirstname() == stufirstid && head->getNum() == stuid) {
        fhead->setnext(head->getnext());
        cout << "学号为" << stufirstid << stuid << "的学生已被删除\n";
        delete head;
        return true;
      }
      fhead = head;
      head = head->getnext();
    }
    cout << "要删除的学生不存在，无法删除!" << endl;
    return false;
  }
}
//保存记录
void AddressBook::saveRecords() {
  ofstream fout("addressbook.txt");
  person *pe = myfirst;
  while (pe) {
    fout << pe->getfirstname() << "\t" << pe->getNum() << "\t" << pe->getname()
         << "\t" << pe->getsex() << "\t" << pe->getage() << "\t" << pe->gettel()
         << "\t" << pe->getemail() << "\t" << pe->getpostcode() << "\t"
         << pe->getIDnumber() << "\n";
    pe = pe->getnext();
  }
  fout.close();
  cout << "数据保存完毕!\n";
}
//读取记录
void AddressBook::loadRecords() {
  int Num, age, firstname; //学号
  char name[40], sex[10], tel[20], email[60], postcode[10], IDnumber[30];
  ifstream fin("../data/info.dat");
  int i = 0;
  while (fin >> firstname >> Num >> name >> sex >> age >> tel >> email >>
         postcode >> IDnumber) {
    insert(Num, firstname, name, sex, age, tel, email, postcode, IDnumber);
    i++;
  }
  if (i == 0) {
    cout << "加载失败,目前文档内没有数据!" << endl;
    fin.close();
  } else {
    fin.close();
    cout << "已成功加载" << i << "行数据" << endl;
    displayRecord();
  }
}

void menu() {
  AddressBook target;
  int i;

  while (true) {
    cout << "    "
            "=======================欢迎使用学生通讯录管理系统================="
            "====="
         << endl;
    cout << "    请输入一个数字选择操作项,以.提示输入，以回车符号结束：        "
            "    　　     "
         << endl;
    cout << "    1.添加或新建学生的通讯联系方式信息。  addRecord()           "
            "　  　无参数!"
         << endl;
    cout << "    2.显示学生的通讯联系方式的记录。      displayRecord()        "
            "　  无参数!"
         << endl;
    cout << "    3.修改一个学生的通讯联系方式信息。    update()               "
            "　  无参数!"
         << endl;
    cout << "    4.删除一个学生的通讯联系方式信息。    removeRecord()          "
            "　 无参数!"
         << endl;
    cout << "    5.查询指定学生的通讯联系方式信息。    queryRecord()          "
            "　  无参数!"
         << endl;
    cout << "    6.加载文件中学生通讯联系方式信息。    loadRecords()           "
            "　 无参数!"
         << endl;
    cout << "    7.保存记录。                       saveRecords()           　 "
            "无参数!"
         << endl;
    cout << "    8.清除所有记录。                    clear()                 "
            "　 无参数!"
         << endl;
    cout << "    9.退出学生通讯录管理系统!            Exit()                   "
            "　无参数!"
         << endl;
    cout << "    "
            "=================================================================="
            "====="
         << endl;
    cout << ".";
    cin >> i;
    if (i < 1 || i > 9) {
      cout << "输入错误，请重新输入!" << endl;
      continue;
    }
    if (!(i == 9 || i == 6 || i == 1) &&
        Enterflag == 0) // 如果第一次输入函数不是建立、打开或退出，则重新输入
    {
      cout << "请先建立或者从文件载入一组联系方式信息!" << endl;
      continue;
    }
    Enterflag = 1;
    switch (i) {
    case 1:
      target.addRecord();
      break;
    case 2:
      target.displayRecord();
      break;
    case 3:
      target.update();
      break;
    case 4:
      target.removeRecord();
      break;
    case 5:
      target.queryRecord();
      break;
    case 6:
      target.loadRecords();
      break;
    case 7:
      target.saveRecords();
      break;
    case 8:
      target.clear();
      break;
    case 9:
      exit(1);
    }
  }
}

int main() {
  menu();

  return 0;
}