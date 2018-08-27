//
// Created by mac on 2018/8/27.
//

#ifndef SHOPMANAGER_VIEW_HPP
#define SHOPMANAGER_VIEW_HPP

#include "../include/custom.h"
#include "../include/admin.h"
#include "../include/goods.h"

//超级管理员界面
void superman(alklist &head) {
  int a = 1, sign = 1, choice;
  string ID, mima;
  while (sign != 0) {
    cout << "请输入帐号：" << endl;
    cin >> ID;
    cout << "请输入密码" << endl;
    cin >> mima;
    if (ID != "asd" || mima != "123") {
      cout << "输入有误，是否重新登录？" << endl;
      cout << "<继续>请按1  <结束>请按0" << endl;
      cin >> sign;
      if (sign == 0) {
        system("cls");
        return;
      }
      else continue;
    }
    while (a != 0) {
      system("cls");
      cout << "===============================================================================\n";
      cout << "||                         欢迎您，尊敬的超级管理员                          ||\n";
      cout << "===============================================================================\n";
      cout << "||                                                                           ||\n";
      cout << "|| \t \t \t      [1]添加管理员 \t\t\t             ||\n";
      cout << "|| \t \t \t      [2]删除管理员 \t\t\t             ||\n";
      cout << "|| \t \t \t      [0]  退出  \t\t\t             ||\n";
      cout << "===============================================================================\n";
      cout << "请输入操作选项: ";
      cin >> choice;
      if (choice != 0 && choice != 1 && choice != 2) {
        cout << "输入有误，请重新输入";
        continue;
      }
      switch (choice) {
        case 1: {
          admin::adminCreate(*head);
          system("clear");
          break;
        }

        case 2: {
          admin::adminDelete(*head);
          system("clear");
          break;
        }

        case 0: { return; }
          return;
        default: {break;}
      }//switch
      cout << "是否继续执行超级管理员权限？<继续>请按1  <结束>请按0" << endl;
      cin >> a;
      if (a == 0) return;
    }//里层while的a
  }//最外层while的sign
}

//管理者功能界面
void Admin_show(alklist &head, clklist &buyer, sqlist &Goods) {
  int a = 1, choice;//a用于循环，choice用于功能选择
  string ID, passwd;
  cout << "请输入管理员帐号：";
  cin >> ID;
  cout << "请输入管理员密码:";
  cin >> passwd;
  apoint p;
  p = head;
  if (admin::adminEnder(*head, ID, passwd) == 1) {
    while (a != 0) {
      system("cls");
      cout << "===============================================================================\n";
      cout << "||                         欢迎您，尊敬的管理者                              ||\n";
      cout << "===============================================================================\n";
      cout << "||                                                                           ||\n";
      cout << "|| \t [1]商品录入 \t [2]商品修改 \t[3]商品查询\t        ||\n";
      cout << "|| \t [4]商品删除 \t [5]商品排序 \t[6]商品库存\t        ||\n";
      cout << "|| \t [7]删除普通用户 \t [0]退出 \t\t        ||\n";
      cout << "===============================================================================\n";
      cout << "请输入操作选项: ";
      cin >> choice;
      switch (choice) {
        case 1:
          Good_add(Goods);
          system("clear");
          break;
        case 2:
          Good_change(Goods);
          system("clear");
          break;
        case 3:
          Good_inquire(Goods);
          system("clear");
          break;
        case 4:
          Good_delete(Goods);
          system("clear");
          break;
        case 5:
          Good_range(Goods);
          system("clear");
          break;
        case 6:
          Good_all(Goods);
          system("clear");
          break;
        case 7:
          custom::custom_delete(buyer);
          system("clear");
          break;
        case 0:
          system("clear");
          return;
        default:
          break;
      }//switch的
    }//while的
  }//if的
  else cout << "管理员帐号不存在!" << endl;

}

//普通用户功能界面
void custom_showall(clklist &head, sqlist &Goods) {
  int a = 1, choice, sign = 1;//a用于循环，choice用于功能选择
  string ID, mima;
  while (sign != 0) {
    cout << "请输入帐号：" << endl;
    cin >> ID;
    cout << "请输入密码" << endl;
    cin >> mima;
    /*cpointer p;
    p=head;*/
    if (custom::customEnder(*head, ID, mima) == 1) {
      while (a != 0) {
        system("cls");
        cout << "===============================================================================\n";
        cout << "||                         欢迎您，尊敬的用户                              ||\n";
        cout << "===============================================================================\n";
        cout << "||                                                                           ||\n";
        cout << "|| \t [1]商品查询 \t [2]商品排序 \t[3]商品库存\t        ||\n";
        cout << "|| \t [4]商品购买 \t [5]修改密码 \t[6]充值    [0]退出        ||\n";
        cout << "===============================================================================\n";
        cout << "请输入操作选项: ";
        cin >> choice;
        switch (choice) {
          case 1:
            Good_inquire(Goods);
            system("cls");
            break;
          case 2:
            Good_range(Goods);
            system("cls");
            break;
          case 3:
            Good_all(Goods);
            system("cls");
            break;
          case 4:
            Good_buy(Goods, head, ID);
            system("cls");
            break;
          case 5:
            custom_change(head, ID);
            system("cls");
            break;
          case 6:
            custom_addmoney(head, ID);
            system("cls");
            break;
          case 0:system("cls");
            return;
        }//switch的
      }//while的
    }//if的
    else {
      cout << "是否重新输入？<继续>请按1  <结束>请按0" << endl;
      cin >> sign;//while循环判断条件，所以不需要用if
    }
  }
}

//普通用户选择（登录||注册）
void custom_show(clklist &head, sqlist &Goods) {
  int a = 1, choice;
  while (a != 0) {
    system("cls");
    cout << "===============================================================================\n";
    cout << "||                         欢迎您，尊敬的用户                              ||\n";
    cout << "===============================================================================\n";
    cout << "||                                                                           ||\n";
    cout << "|| \t \t \t [1]用户登录 \t\t\t        ||\n";
    cout << "|| \t \t \t [2]新用户注册 \t\t\t        ||\n";
    cout << "|| \t \t \t [0]返回 \t\t\t        ||\n";
    cout << "===============================================================================\n";
    cout << "请选择您的身份: ";
    cin >> choice;
    if (choice != 0 && choice != 1 && choice != 2) {
      cout << "输入有误，请重新输入";
      continue;
    }
    switch (choice) {
      case 1:
        custom_showall(head, Goods);
        system("cls");
        break;
      case 2:
        custom_creat(head);
        system("cls");
        break;
      case 0:return;
    }//switch
    cout << "是否继续用户模块？<继续>请按1  <结束>请按0" << endl;
    cin >> a;
    if (a == 0) break;
  }
}

//main()函数主界面
void show()//
{
  admin *ad;//定义一个管理员

  custom *buyer;//定义一个普通用户

  sqlist Goods;//定义一个商品链表

  int choice;
  while (true) {
    admin::getAdmin(*ad);//获取管理员文件中的信息，导入Ad链表中
    custom::getCustom(buyer);//获取普通用户文件中的信息，导入buyer链表中
    custom::Good_get(Goods);//从文件中获取商品信息
    system("clear");
    cout << "===============================================================================\n";
    cout << "||                         欢迎使用超市管理系统                              ||\n";
    cout << "===============================================================================\n";
    cout << "||                                                                           ||\n";
    cout << "|| \t [1]超级管理员  \t[2]管理员 \t [3]顾客 \t [0]退出        ||\n";
    cout << "===============================================================================\n";
    cout << "请选择您的身份: ";
    cin >> choice;
    switch (choice) {
      case 1:superman(*ad);
        break;//超级管理员功能界面
      case 2:Admin_show(*ad, buyer, Goods);
        break;
      case 3:custom_show(buyer, Goods);
        break;
      case 0:system("clear");
        return;
      default:cout << "Operator error.Please input again: ";
        system("clear");
    }
  }
}
#endif //SHOPMANAGER_VIEW_H
