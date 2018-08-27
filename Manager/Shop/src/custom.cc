//
// Created by mac on 2018/8/27.
//

#include "../include/custom.h"

custom::custom() {}

custom::~custom() {}

//Init custom list
clklist customInit() {
  custom *head;
  head = new custom;
  head->next = nullptr;
  return head;
}

// save data to file
void custom::saveCustom(custom &cs) {
  custom *p;
  ofstream ofs("../data/info.dat", ios::out);
  ofs << "Custom number：" << "  " << buyerNum << endl;//文本第一行显示共有多少普通用户
  p = cs.next;
  while (p != nullptr) {
    ofs << p->customId << "\t" << p->customName << "\t" << p->customPasswd << "\t" << p->money;
    cout << endl;
    p = p->next;
  }
  cout << "Custom information saved!" << endl;
  ofs.close();

}

// Verify account
void customCreate(custom &cs) {
  custom *s, *p;
  s = new custom;

  string id, name, passwd;
  int sign = true;
  bool flag = true;
  string status = "n";

  while (sign) {
    cout << "Id: ";
    cin >> id;
    p = cs.next;
    while (p != nullptr) {
      if (p->customId == id)
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

    s->customId = id;
    s->customName = name;
    s->customPasswd = passwd;

    s->money = 0;
    s->next = cs.next;
    cs.next = s;
    // add admin people numbers.
    buyerNum += 1;
    custom::saveCustom(cs);
    cout << "Again？(y/n): ";
    cin >> status;
    if (status == "y")
      sign = true;
    else
      break;

    cin >> sign;
  }
}

// Sign account
int custom_ender(custom &cs, string id, string passwd) {
  custom *p;
  p = &cs;
  while (p != nullptr) {
    if (p->customId == id && p->customPasswd == passwd)
      return 1;
    else p = p->next;
  }
  cout << "Account do'ont exist!" << endl;
  return 0;

}

// Detect user level
cpoint custom_locate(clklist &head, string id){
  cpoint p,q;
  p=head;
  int flat = 0;
  while(p->next!=NULL&&flat==0){
    if(p->next->customId==id){
      q=p->next;
      return q;
    }
    else p=p->next;
  }
}

// Get the general user information and import the linked list
clklist getCustom(clklist &buyer){
  cpoint s,p;//s用于存储用户信息，p用于buyer的连接
  string numname;
  string ID,name,passwd;
  double money;
  buyer->next=NULL;
  p=buyer;
  ifstream ifile("C:\\普通用户信息.txt",ios::in);
  if(!ifile){
    cerr<<"用户信息查询出错"<<endl;return 0;
  }
  ifile>>numname;
  ifile>>buyerNum;//从文件中提取用户个数，用于for循环
  for(int i=1;i<=buyerNum;i++){
    ifile>>ID;
    ifile>>name;
    ifile>>passwd;
    ifile>>money;
    s=new custom;
    s->customId=ID;
    s->customName=name;
    s->customPasswd=passwd;
    s->money=money;
    s->next=p->next;
    p->next=s;
  }
  buyer=p;
  ifile.close();
  return buyer;
}
clklist getCustom(custom &cs) {
  custom *s, *p;//s用于存储用户信息，p用于buyer的连接
  string numName;
  string id, name, passwd;
  double money;
  cs.next = nullptr;
  p = &cs;
  ifstream ifs("../data/info.dat", ios::in);
  if (!ifs) {
    cerr << "Search custom information error!";
    cout << endl;
    return nullptr;
  }
  ifs >> numName;
  ifs >> buyerNum;

  for (int i = 1; i <= buyerNum; i++) {
    ifs >> id;
    ifs >> name;
    ifs >> passwd;
    ifs >> money;
    s = new custom;
    s->customId = id;
    s->customName = name;
    s->customPasswd = passwd;
    s->money = money;
    s->next = p->next;
    p->next = s;
  }
  // close file io
  ifs.close();
}

// Modifly user
void custom::customChange(custom &cs, string id) {
  custom *p;
  p = &cs;

  bool sign = true;
  string status = "n";

  while (sign) {
    while (p != nullptr) {
      if (p->customId == id) {
        cout << "Input new password: ";
        cin >> p->customPasswd;
        cout << "Change password successful!" << endl;
        break;
      } else p = p->next;
    }
    saveCustom(cs);
    cout << "Again？(y/n): ";
    cin >> status;
    if (status == "y")
      sign = true;
    else
      break;

    cin >> sign;
  }
}

// Delete user
void custom::customDelete(custom &cs) {
  custom *p, *q;
  p = &cs;

  bool sign = true;
  bool flag = true;
  string status = "n";
  string id;

  while (sign) {
    cout << "请输入要删除的用户帐号：";
    cin >> id;
    while (p->next != nullptr && flag) {
      if (p->next->customId == id) {
        q = p->next;
        p->next = q->next;
        delete q;
        buyerNum--;

        flag = false;
        cout << "Delete successful!" << endl;
      } else
          p = p->next;
    }
    if (!flag)
      cout << "Custom d'nt!" << endl;
    saveCustom(cs);
    cout << "Again？(y/n): ";
    cin >> status;
    if (status == "y")
      sign = true;
    else
      break;

    cin >> sign;
  }
}

// Add money to card
void addMoneyCustom(clklist &head, string id) {
  custom *p;

  bool sign = true;
  string status = "n";

  p = custom_locate(head, id);
  string acard;
  string card1 = "xcrj8888", card2 = "xcrj8";
  while (sign != 0) {
    cout << "Please enter your top-up card number: ";
    cin >> acard;
    if (acard != card1 && acard != card2)
      cout << "Recharge card is invalid." << endl;

    if (acard == card1) {
      p->money += 500;
      cout << "Top-up success！" << endl;
      cout << "Account balance：" << p->money << endl;

    };

    if (acard == card2) {
      p->money += 1000;
      cout << "Top-up success！" << endl;
      cout << "Account balance：" << p->money << endl;

    };

    custom::saveCustom(*head);
    cout << "Again？(y/n): ";
    cin >> status;
    if (status == "y")
      sign = true;
    else
      break;

    cin >> sign;
  }
}
