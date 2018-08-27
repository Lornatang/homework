//
// Create by mac 2018/08/27
//

#include "../include/admin.h"

admin::admin() = default;

admin::~admin() {}

//管理员函数模块
//初始化，建表
apoint adminInit() {
  admin *head;
  head = new admin;
  head->next = nullptr;
  return head;
}

// save data to file
void admin::saveAdmin(admin &ad) {
  apoint p;
  ofstream ofs("../data/info.dat", ios::out);
  ofs << "Admin number: " << adminNum << endl;//文本第一行显示共有多少管理员
  p = ad.next;
  while (p != nullptr) {
    ofs << p->adminId << "\t" << p->adminName << "\t" << p->adminPasswd << endl;
    p = p->next;
  }
  cout << "Admin infomation saved!" << endl;
  ofs.close();
}

// Verify account
int admin::adminEnder(admin &ad, string id, string passwd) {
  admin *p;
  p = ad.next;
  while (p != nullptr) {
    if (p->adminId == id && p->adminPasswd == passwd)
      return 1;

    else p = p->next;
  }
  cout << "Admin account do'not exist!" << endl;
  return 0;
}

// Sign account
void admin::adminCreate(admin &ad) {
  admin *s, *p;
  s = new admin;

  string id, name, passwd;
  bool sign = true;
  bool flag = true;
  string status = "n";

  while (sign) {
    cout << "Id:";
    cin >> id;
    p = ad.next;
    while (p != nullptr) {
      if (p->adminId == id)
        flag = false;
      p = p->next;
    }
    if (!flag) {
      cout << "Admin account is exist! Enter again: ";
      continue;
    }
    cout << "Account password: ";
    cin >> passwd;
    cout << "Account name: ";
    cin >> name;

    s->adminId = id;
    s->adminName = name;
    s->adminPasswd = passwd;
    s->next = ad.next;
    ad.next = s;
    // add admin people numbers.
    adminNum += 1;
    admin::saveAdmin(ad);
    cout << "Again？(y/n): ";
    cin >> status;
    if (status == "y")
      sign = true;
    else
      break;

    cin >> sign;
  }
}

// Delete admin information
void admin::adminDelete(admin &ad) {
  admin *p, *q;
  p = new admin;

  // Setting loop status
  bool sign = true;
  bool flag = false;
  string id;

  while (sign != 0) {
    cout << "Input you want delete admin account id: ";
    cin >> id;
    while (p->next != nullptr && !flag) {
      if (p->next->adminId == id) {
        q = p->next;
        p->next = q->next;
        delete q;
        adminNum--;
        flag = true;
        cout << "Delete successful!" << endl;
      } else p = p->next;
    }
    if (!flag) cout << "管理员不存在!" << endl;
    admin::saveAdmin(ad);
    cout << "是否继续删除？<继续>请按1  <结束>请按0" << endl;
    cin >> sign;//while循环判断条件，所以不需要用if
  }

}

//获取管理员信息，导入链表
int admin::getAdmin(admin &ad) {
  admin *s, *p;//s用于存储管理员信息，p用于ad的连接

  s = new admin;
  string numName;
  string id, name, passwd;

  ad.next = nullptr;
  p = &ad;
  ifstream ifs("../data/info.dat", ios::in);
  if (!ifs) {
    cerr << "Search admin information error!";
    cout << endl;
    return 0;
  }
  ifs >> numName;
  ifs >> adminNum;//从文件中提取管理员个数，用于for循环
  for (int i = 1; i <= adminNum; i++) {
    ifs >> id;
    ifs >> name;
    ifs >> passwd;

    s->adminId = id;
    s->adminName = name;
    s->adminPasswd = passwd;
    s->next = p->next;
    p->next = s;
  }
  ifs.close();
  return 0;
}

