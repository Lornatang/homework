//
// Created by mac on 2018/8/27.
//

#include "../include/goods.h"
#include "../include/custom.h"
//商品函数模块
//商品信息验证
//编号验证
int Good_ender1(sqlist &Goods, string ID) {//对比相同返回1
  for (int i = 0; i < goodNum; i++) {
    if (Goods.Good[i].Good_ID == ID) return 1;
  }
  return 0;
}

//名称验证
int Good_ender2(sqlist &Goods, string name) {//对比相同返回1
  for (int i = 0; i < goodNum; i++) {
    if (Goods.Good[i].Good_name == name) return 1;
  }
  return 0;
}

//定位商品在链表中的位置
//编号定位
int Good_locate1(sqlist &Goods, string ID) {
  int i = 0;
  while (i < goodNum && Goods.Good[i].Good_ID != ID) i++;
  if (i < goodNum) return i;//成功定位到位置
  else return 0;//i超出范围
}

//名称定位
int Good_locate2(sqlist &Goods, string name) {
  int i = 0;
  while (i < goodNum && Goods.Good[i].Good_name != name) i++;
  if (i < goodNum) return i;//成功定位到位置
  else return 0;//i超出范围
}

//获取商品信息，导入链表
void Good_get(sqlist &Goods) {
  ifstream ifile("C:\\商品信息.txt", ios::in);
  if (!ifile) {
    cout << "文件打开失败！" << endl;
    return;
  }
  string IDtitle, nametitle, piecetitle, lasttitle;//用于显示（货品编码 货品名字 单价 存货量）标题
  string ID, name, title;//title用于显示编号标题
  double piece;
  int last, sum;//sum用于显示商品种类
  ifile >> title;//输出“商品种类共有”
  ifile >> sum;//输出商品种类
  goodNum = sum;
  ifile >> IDtitle >> nametitle >> piecetitle >> lasttitle;//输出编号，名称，单价，库存
  for (int i = 0; i < sum; i++) {
    ifile >> ID >> name >> piece >> last;
    Goods.Good[i].Good_ID = ID;
    Goods.Good[i].Good_name = name;
    Goods.Good[i].piece = piece;
    Goods.Good[i].last = last;
  }
  cout << "成功读取了 " << sum << " 种商品" << endl;
  ifile.close();
}

//商品信息保存
void Good_save(sqlist &Goods) {
  ofstream ofile("C:\\商品信息.txt", ios::out);
  ofile << "商品种类：" << "\t\t" << goodNum << endl;//文本第一行显示共有多少种商品
  ofile << "商品编号" << "\t\t" << "商品名称" << "\t\t" << "商品单价" << "\t\t" << "商品库存" << endl;
  for (int i = 0; i < goodNum; i++) {
    ofile << Goods.Good[i].Good_ID << "\t\t" << Goods.Good[i].Good_name << "\t\t" << Goods.Good[i].piece << "\t\t"
          << Goods.Good[i].last << endl;
  }
  cout << "商品信息保存成功" << endl;
  ofile.close();
}

//商品录入(新商品录入+旧商品添加)
void Good_add(sqlist &Goods) {
  string ID, name;
  double piece;
  int last, sign, flat = 1;//last为商品库存，sign用于判断选择
  fstream ifile("C:\\商品信息.txt", ios::in);
  for (; flat != 0;) {
    cout << "请输入商品编号:";
    cin >> ID;
    if (Good_ender1(Goods, ID) == 0) {
      cout << "请输入商品名称:";
      cin >> name;
      if (Good_ender2(Goods, name) == 0) {
        cout << "请输入商品单价:";
        cin >> piece;
        cout << "请输入商品数量:";
        cin >> last;
        Goods.Good[goodNum].Good_ID = ID;
        Goods.Good[goodNum].Good_name = name;
        Goods.Good[goodNum].piece = piece;
        Goods.Good[goodNum].last = last;
        goodNum++;//添加完信息就自加1
        Good_save(Goods);//添加完就保存至商品信息.txt
        cout << "是否继续录入？<继续>请按1  <结束>请按0" << endl;
        cin >> sign;
        if (sign == 0) break;
      } else {
        cout << "商品名称已存在！<重新输入>请按1  <结束>请按0" << endl;
        cin >> flat;
      }
    } else {
      cout << "商品编号已存在！<重新输入>请按1  <结束>请按0" << endl;
      cin >> flat;
    }
  }
}

//商品修改
void Good_change(sqlist &Goods) {
  string ID, name;
  int sign;//sign用于定位要修改商品的位置
  int a, flat = 1;//a用于switch
  for (; flat != 0;) {
    cout << "<输入要修改的商品编号>请按1   <输入要修改的商品名称>请按2" << endl;
    cin >> a;
    if (a != 1 && a != 2) {
      cout << "选择有误，请重新输入" << endl;
      continue;
    }
    switch (a) {
      case 1: {
        cout << "请输入商品编号：";
        cin >> ID;
        if (Good_ender1(Goods, ID) == 1) {
          sign = Good_locate1(Goods, ID);
          cout << "商品编号:" << Goods.Good[sign].Good_ID << endl;
          cout << "商品名称:" << Goods.Good[sign].Good_name << endl;
          cout << "商品单价:" << Goods.Good[sign].piece << endl;
          cout << "商品库存:" << Goods.Good[sign].last << endl;
          cout << "请输入修改后的信息：" << endl;
          cout << "商品编号:";
          cin >> Goods.Good[sign].Good_ID;
          cout << "商品名称:";
          cin >> Goods.Good[sign].Good_name;
          cout << "商品单价:";
          cin >> Goods.Good[sign].piece;
          cout << "商品库存:";
          cin >> Goods.Good[sign].last;
          Good_save(Goods);//保存信息
          cout << "修改成功" << endl;
        } else cout << "商品不存在!" << endl;
        break;
      }
      case 2: {
        cout << "请输入商品名称：";
        cin >> name;
        if (Good_ender2(Goods, name) == 1) {
          sign = Good_locate2(Goods, name);
          cout << "商品编号:" << Goods.Good[sign].Good_ID << endl;
          cout << "商品名称:" << Goods.Good[sign].Good_name << endl;
          cout << "商品单价:" << Goods.Good[sign].piece << endl;
          cout << "商品库存:" << Goods.Good[sign].last << endl;
          cout << "请输入修改后的信息：" << endl;
          cout << "商品编号:";
          cin >> Goods.Good[sign].Good_ID;
          cout << "商品名称:";
          cin >> Goods.Good[sign].Good_name;
          cout << "商品单价:";
          cin >> Goods.Good[sign].piece;
          cout << "商品库存:";
          cin >> Goods.Good[sign].last;
          Good_save(Goods);//保存信息
          cout << "修改成功" << endl;
        } else cout << "商品不存在!" << endl;
        break;
      }
    }//switch的
    cout << "<继续修改>请按1  <退出>请按0" << endl;
    cin >> flat;
  }//for循环的
}

//商品查询
void Good_inquire(sqlist &Goods) {
  string ID, name;
  int a, sign, flat = 1;
  for (; flat != 0;) {
    cout << "<按商品编号查询>请按1   <按商品名称查询>请按2" << endl;
    cin >> a;
    if (a != 1 && a != 2) {
      cout << "选择有误，请重新输入" << endl;
      continue;
    }
    switch (a) {
      case 1: {
        cout << "请输入商品编号：";
        cin >> ID;
        if (Good_ender1(Goods, ID) == 1) {
          sign = Good_locate1(Goods, ID);
          cout << "商品编号:" << Goods.Good[sign].Good_ID << endl;
          cout << "商品名称:" << Goods.Good[sign].Good_name << endl;
          cout << "商品单价:" << Goods.Good[sign].piece << endl;
          cout << "商品库存:" << Goods.Good[sign].last << endl;
        } else cout << "商品不存在!" << endl;
        break;
      }
      case 2: {
        cout << "请输入商品名称：";
        cin >> name;
        if (Good_ender2(Goods, name) == 1) {
          sign = Good_locate2(Goods, name);
          cout << "商品编号:" << Goods.Good[sign].Good_ID << endl;
          cout << "商品名称:" << Goods.Good[sign].Good_name << endl;
          cout << "商品单价:" << Goods.Good[sign].piece << endl;
          cout << "商品库存:" << Goods.Good[sign].last << endl;
        } else cout << "商品不存在!" << endl;
        break;
      }
    }//switch的
    cout << "是否继续查询？<继续>请按1  <结束>请按0" << endl;
    cin >> flat;
    if (flat == 0) break;
  }//for循环的
}

//商品删除
void Good_delete(sqlist &Goods) {
  int a, sign, flat = 1;
  string ID, name;
  for (; flat != 0;) {
    cout << "<输入要删除的商品编号>请按1   <输入要删除的商品名称>请按2" << endl;
    cin >> a;
    if (a != 1 && a != 2) {
      cout << "选择有误，请重新输入" << endl;
      continue;
    }
    switch (a) {
      case 1: {
        cout << "请输入要删除的商品编号:";
        cin >> ID;
        if (Good_ender1(Goods, ID) == 1) {
          sign = Good_locate1(Goods, ID);
          for (int i = sign; i < goodNum; i++) {
            Goods.Good[i] = Goods.Good[i + 1];
          }
          goodNum--;
          Good_save(Goods);
          cout << "删除成功！" << endl;
        } else cout << "商品不存在!" << endl;
        break;
      }
      case 2: {
        cout << "请输入要删除的商品名称:";
        cin >> name;
        if (Good_ender2(Goods, name) == 1) {
          sign = Good_locate2(Goods, name);
          for (int i = sign; i < goodNum; i++) {
            Goods.Good[i] = Goods.Good[i + 1];
          }
          goodNum--;
          Good_save(Goods);
          cout << "删除成功！" << endl;
        } else cout << "商品不存在!" << endl;
        break;
      }
    }//switch的
    cout << "是否继续删除？<继续>请按1  <结束>请按0" << endl;
    cin >> sign;
    if (sign == 0) break;
  }//for循环的
}

//商品排序
void Good_range(sqlist Go) {
  goods p;
  p.piece = 0;
  p.last = 0;
  int a, flag = 0, flat = 1;
  for (; flat != 0;) {
    cout << "<按商品编号排序>请按1  <按商品单价排序>请按2  <按库存数量排序>请按3  <退出>请按0" << endl;
    cin >> a;
    if (a != 0 && a != 1 && a != 2 && a != 3) {
      cout << "选择有误，请重新输入" << endl;
      continue;
    }
    switch (a) {
      case 1: {
        for (int i = 0; i < goodNum; i++) {
          for (int j = goodNum; j >= i + 1; j--) {
            if (Go.Good[j].Good_ID < Go.Good[j - 1].Good_ID) {//比较编号大小，小的在前面，大的在后面
              flag = 1;
              p = Go.Good[j];
              Go.Good[j] = Go.Good[j - 1];
              Go.Good[j - 1] = p;
            }
          }//jfor的
          if (!flag) break;
        }//ifor的
        cout << "商品编号" << setw(10) << "商品名称" << setw(10) << "商品单价" << setw(10) << "商品库存" << endl;
        for (int i = 1; i <= goodNum; i++) {
          cout << Go.Good[i].Good_ID << setw(13) << Go.Good[i].Good_name << setw(8) << Go.Good[i].piece << setw(10)
               << Go.Good[i].last << endl;
        }
        break;
      }
      case 2: {
        for (int i = 0; i < goodNum; i++) {
          for (int j = goodNum; j >= i + 1; j--) {
            if (Go.Good[j].piece < Go.Good[j - 1].piece) {//比较单价大小，小的在前面，大的在后面
              flag = 1;
              p = Go.Good[j];
              Go.Good[j] = Go.Good[j - 1];
              Go.Good[j - 1] = p;
            }
          }//jfor的
          if (!flag) break;
        }//ifor的
        cout << "商品编号" << setw(10) << "商品名称" << setw(10) << "商品单价" << setw(10) << "商品库存" << endl;
        for (int i = 1; i <= goodNum; i++) {
          cout << Go.Good[i].Good_ID << setw(13) << Go.Good[i].Good_name << setw(8) << Go.Good[i].piece << setw(10)
               << Go.Good[i].last << endl;
        }
        break;
      }
      case 3: {
        for (int i = 0; i < goodNum; i++) {
          for (int j = goodNum; j >= i + 1; j--) {
            if (Go.Good[j].last < Go.Good[j - 1].last) {//比较编号大小，小的在前面，大的在后面
              flag = 1;
              p = Go.Good[j];
              Go.Good[j] = Go.Good[j - 1];
              Go.Good[j - 1] = p;
            }
          }//jfor的
          if (!flag) break;
        }//ifor的
        cout << "商品编号" << setw(10) << "商品名称" << setw(10) << "商品单价" << setw(10) << "商品库存" << endl;
        for (int i = 1; i <= goodNum; i++) {
          cout << Go.Good[i].Good_ID << setw(13) << Go.Good[i].Good_name << setw(8) << Go.Good[i].piece << setw(10)
               << Go.Good[i].last << endl;
        }
        break;
      }//case3的
      case 0:return;
    }//switch的
  }//最外层for的
}

//购买商品
void Good_buy(sqlist &Goods, custom &cs, string cID) {//cID为用户帐号
  string ID, name;
  int a, shu, sign, flat = 1;
  cpoint *p;
  p = custom::custom_locate(cs, cID);
  for (; flat != 0;) {
    cout << "<输入商品编号购买>请按1   <输入商品名称购买>请按2" << endl;
    cin >> a;
    if (a != 1 && a != 2) {
      cout << "输入有误，请重新输入" << endl;
      continue;
    }
    switch (a) {
      case 1: {
        cout << "请输入商品编号：";
        cin >> ID;
        if (Good_ender1(Goods, ID) == 1) {
          sign = Good_locate1(Goods, ID);
          cout << "请输入购买数量：";
          cin >> shu;
          if (shu <= Goods.Good[sign].last) {
            if (p->money < Goods.Good[sign].piece * shu) {
              cout << "余额不足，请充值！" << endl;
              cout << "是否前往充值？<充值>请按1  <否>请按0" << endl;
              cin >> flat;
              if (flat == 0) break;
              if (flat == 1) return;
            }
            Goods.Good[sign].last = Goods.Good[sign].last - shu;
            cout << "购买成功" << endl;
            p->money = p->money - Goods.Good[sign].piece * shu;//账户余额减少，扣费成功
            custom::saveCustom(cs);
            cout << "账户余额：" << p->money << endl;
            Good_save(Goods);
          } else cout << "库存不足！" << endl;
        } else cout << "找不到相应商品，购买失败" << endl;
        break;
      }
      case 2: {
        cout << "请输入商品名称：";
        cin >> name;
        if (Good_ender2(Goods, name) == 1) {
          sign = Good_locate2(Goods, name);
          cout << "请输入购买数量：";
          cin >> shu;
          if (shu <= Goods.Good[sign].last) {
            if (p->money < Goods.Good[sign].piece * shu) {
              cout << "余额不足，请充值！" << endl;
              cout << "是否前往充值？<充值>请按1  <否>请按0" << endl;
              cin >> flat;
              if (flat == 0) break;
              if (flat == 1) return;
            }
            Goods.Good[sign].last = Goods.Good[sign].last - shu;
            cout << "购买成功" << endl;
            p->money = p->money - Goods.Good[sign].piece * shu;//账户余额减少，扣费成功
            custom::saveCustom(cs);
            cout << "账户余额：" << p->money << endl;
            Good_save(Goods);
          } else cout << "库存不足！" << endl;
        } else cout << "找不到相应商品，购买失败" << endl;
        break;
      }
    }//switch的
    cout << "是否继续购物？<继续>请按1  <结束>请按0" << endl;
    cin >> flat;
    if (flat == 0) break;
  }//for的
}

//输出商品的所有库存信息
void Good_all(sqlist &Goods) {
  int flat = 1;
  for (; flat != 0;) {
    cout << "商品编号" << setw(10) << "商品名称" << setw(10) << "商品单价" << setw(10) << "商品库存" << endl;
    for (int i = 0; i < goodNum; i++) {
      cout << Goods.Good[i].Good_ID << setw(13) << Goods.Good[i].Good_name << setw(8) << Goods.Good[i].piece << setw(10)
           << Goods.Good[i].last << endl;
    }
    cout << "是否继续该模块？<继续>请按1  <结束>请按0" << endl;
    cin >> flat;
    if (flat == 0) break;
  }
}
