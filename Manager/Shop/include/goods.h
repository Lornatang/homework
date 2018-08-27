//
// Created by mac on 2018/8/27.
//

#ifndef SHOPMANAGER_GOODS_H
#define SHOPMANAGER_GOODS_H

int goodNum = 0;

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// goods
struct goods {
  string Good_name;//商品名称
  string Good_ID;//商品编号
  double piece;//商品价格
  int last;//库存数量

  //void Good_all() {}
  static void Good_add(goods &Goods);
  static void Good_change(goods &Goods);
  static void Good_inquire(goods &Goods);
  static void Good_delete(goods &Goods);
  static void Good_range(goods &Goods);
  static void Good_all(goods &Goods);
};

typedef struct {
  goods Good[9999];
  int n{};
} sqlist;


#endif //SHOPMANAGER_GOODS_H
