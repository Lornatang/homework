//
// Create by mac 2018/08/27
//

#ifndef SHOPMANAGER_ADMIN_H
#define SHOPMANAGER_ADMIN_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int maxsize = 9999;
int adminNum = 0;

// admin
class admin {
 private:
  string adminId;
  string adminName;
  string adminPasswd;
 public:
  admin();
  ~admin();

  string getadminId() { return adminId; }
  string getadminName() { return adminName; }
  string getadminPasswd() { return adminPasswd; }

  void setadminId(string adminId) { adminId = adminId; }
  void setadminName(string adminName) { adminName = adminName; }
  void setadminPasswd(string adminPasswd) { adminPasswd = adminPasswd; }

  static void saveAdmin(admin &ad);
  static int adminEnder(admin &ad, string adminId, string adminPasswd);
  static void adminCreate(admin &ad);
  static void adminDelete(admin &ad);
  static int getAdmin(admin &ad);

  admin *next;
};

typedef admin *apoint;//单链表类型，即头指针类型
typedef apoint alklist;//单链表类型，即头指针类型


#endif  //SHOPMANAGER_ADMIN_H