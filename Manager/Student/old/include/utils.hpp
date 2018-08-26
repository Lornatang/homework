//
// Created by mac on 2018/8/26.
//

#ifndef STUDENT_MANAGER_UTILS_HPP
#define STUDENT_MANAGER_UTILS_HPP

#include "Student.hpp"

//析构函数
Student::~Student() { delete (St); }

//输入学生的信息
void Student::InputStudent() {
  int len = 0; // 学生的人数
  cout << "请输入学生的人数:";
  cin >> len;

  Size = len;

  St = new Student[Size];

  for (int i = 0; i < len; i++) {
    cout << "请输入第" << i + 1 << "个学生的姓名:";
    cin >> St[i].Name;

    cout << "请输入第" << i + 1 << "个学生的年龄:";
    cin >> St[i].Age;

    cout << "请输入第" << i + 1 << "个学生的学号:";
    cin >> St[i].No;

    cout << "请输入第" << i + 1 << "个学生的语文成绩:";
    cin >> St[i].Score[0];

    cout << "请输入第" << i + 1 << "个学生的数学成绩:";
    cin >> St[i].Score[1];

    cout << "请输入第" << i + 1 << "个学生的英语成绩:";
    cin >> St[i].Score[2];

    St[i].Total = St[i].Score[0] + St[i].Score[1] + St[i].Score[2];

    St[i].Ave = St[i].Total / 3.0f;
  }
}

//输出学生的信息
void Student::OutputStudent() {
  cout << "姓名  年龄   学号   语文   数学  英语  总分  平均分" << endl;

  for (int i = 0; i < Size; i++) {
    cout << St[i].Name << "  " << St[i].Age << "  " << St[i].No << "  "
         << St[i].Score[0] << "  " << St[i].Score[1] << "  " << St[i].Score[2]
         << "  " << St[i].Score[2] << "  " << St[i].Total << "  " << St[i].Ave
         << endl;
  }
}

// 删除学生信息
void Student::DeleteStudent() {
  string str;
  cout << "请输入你需要删除的学生的姓名:";
  cin >> str;

  int num = 0; //标记姓名相等时的下标

  //寻找姓名相等时的下标
  for (int i = 0; i < Size; i++) {
    //当姓名相等时
    if (St[i].Name == str) {
      num = i;
    }
  }

  //将后面的学生向前移
  for (int j = num + 1; j < Size; j++) {
    St[j - 1] = St[j];
  }

  Size -= 1; //学生人数减少一个
}

// 查找学生信息
void Student::SearchStudent() {
  string name;
  cout << "请输入你需要查找的学生的姓名:";
  cin >> name;

  int i;

  for (i = 0; i < Size; i++) {
    if (name == St[i].Name) {
      break;
    }
  }

  cout << St[i].Name << " " << St[i].Age << " " << St[i].No << " "
       << St[i].Score[0] << " " << St[i].Score[1] << " " << St[i].Score[2]
       << " " << St[i].Total << " " << St[i].Ave << endl;
}

// 修改学生信息
void Student::ChangeStudent() {
  string name;
  cout << "请输入你需要修改的学生的姓名:";
  cin >> name;

  int i;

  for (i = 0; i < Size; i++) {
    if (name == St[i].Name) {
      break;
    }
  }

  cout << "修改前学生的信息:" << endl;
  cout << St[i].Name << " " << St[i].Age << " " << St[i].No << "  "
       << St[i].Score[0] << " " << St[i].Score[1] << " " << St[i].Score[2]
       << " " << St[i].Total << " " << St[i].Ave << endl
       << endl;

  cout << "请输入学生的姓名:";
  cin >> St[i].Name;

  cout << "请输入学生的年龄:";
  cin >> St[i].Age;

  cout << "请输入第个学生的学号:";
  cin >> St[i].No;

  cout << "请输入学生的语文成绩:";
  cin >> St[i].Score[0];

  cout << "请输入学生的数学成绩:";
  cin >> St[i].Score[1];

  cout << "请输入第学生的英语成绩:";
  cin >> St[i].Score[2];

  St[i].Total = St[i].Score[0] + St[i].Score[1] + St[i].Score[2];

  St[i].Ave = St[i].Total / 3.0f;
}

// 对学生的语文成绩排序
void Student::ScortByChinese() {
  //提供插入数组中的数据
  for (int i = 1; i < Size; i++) {
    int j = i - 1;

    //插入数组中的数据
    Student temp = St[i];

    while (temp.Score[0] > St[j].Score[0] && j >= 0) {
      St[j + 1] = St[j];

      j--;
    }

    St[++j] = temp;
  }
}

// 对学生的数学成绩排序
void Student::ScortByMath() {
  //提供插入数组中的数据
  for (int i = 1; i < Size; i++) {
    int j = i - 1;

    //插入数组中的数据
    Student temp = St[i];

    while (temp.Score[1] > St[j].Score[1] && j >= 0) {
      St[j + 1] = St[j];

      j--;
    }

    St[++j] = temp;
  }
}

// 对学生的英语成绩排序
void Student::ScortByEnglish() {
  //提供插入数组中的数据
  for (int i = 1; i < Size; i++) {
    int j = i - 1;

    //插入数组中的数据
    Student temp = St[i];

    while (temp.Score[2] > St[j].Score[2] && j >= 0) {
      St[j + 1] = St[j];
      j--;
    }

    St[++j] = temp;
  }
}

//对学生的总分排序
void Student::ScortByTotal() {
  //提供插入数组中的数据
  for (int i = 1; i < Size; i++) {
    int j = i - 1;

    //插入数组中的数据
    Student temp = St[i];

    while (temp.Total > St[j].Total && j >= 0) {
      St[j + 1] = St[j];
      j--;
    }

    St[++j] = temp;
  }
}
#endif // STUDENT_MANAGER_UTILS_HPP
