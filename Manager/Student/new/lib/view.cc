#include <utility>

//
// Created by mac on 2018/8/26.
//

#include "../include/view.h"
using namespace std;

View::View() {}

View::~View() {}

/* 欢迎 */
void View:: welcome() {
    system("clear");
    std::cout<<"欢迎来到湖南涉外经济学院计算机应用1603班学生管理系统"<<std::endl;
}

/* 显示菜单 */
void View:: showMenu() {

    std::cout<<"\n";
    std::cout<<"操作步骤"<<std::endl;

    std::cout<<"1. 录入"<<std::endl;
    std::cout<<"2. 修改"<<std::endl;
    std::cout<<"3. 查找"<<std::endl;
    std::cout<<"4. 删除"<<std::endl;
    std::cout<<"5. 显示所有"<<std::endl;
    std::cout<<"6. 保存至文件"<<std::endl;
    std::cout<<"7. 从文件导入"<<std::endl;
    std::cout<<"0. 退出"<<std::endl;
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"请选择操作：";
}


/* View 显示所有学生 */
void View:: showAllStuAtView(const std::map<int, Student> & stu_m1 )
{

    system("clear");
    cout<<"id    |"<<"name  |"<<"age"<<std::endl;
    stuMager cStuMg;
    cStuMg.showAll(stu_m1);

    getchar();
    system("clear");
    welcome();
    showMenu();
}

/* view层 添加一个学生 */
void  View:: addStuAtView( std::map<int, Student> & stu_m1 )
{
    stuMager cStuMg;

    int id = 0;
    std::string name;
    int age = 0;
    Student cStu;

    system("clear");

    std::cout<<"录入\n";
    std::cout<<"id:";
    std::cin>>id;

    std::cout<<"name:";
    std::cin>>name;

    std::cout<<"age:";
    std::cin>>age;

    cStu.setId(id);
    cStu.setName(name);
    cStu.setAge(age);

    // 保存
    cStuMg.addAStu(stu_m1,cStu);

    system("cls");
    welcome();
    showMenu();
}



/* View 查找一个学生 */
void  View::  findStuAtView(const std::map<int, Student> & m1) {

    system("clear");
    int id = 0;
    std::cout<<"请输入要查找学生的id"<<std::endl;
    std::cin>>id;

    stuMager cStuMg;
    Student cStu;
    cStu = cStuMg.findById(m1,id);

    if (cStu.getId()!=-1)
    {
        std::cout<<cStu<<std::endl;
    }
    else
    {
        std::cout<<"查无此人"<<std::endl;
    }

    getchar();
    system("clear");
    welcome();
    showMenu();

}

/* view层删除一个学生 */
void   View:: deleteByIdAtView(std::map<int, Student> & v1) {

    system("clear");
    int id = 0;
    std::cout<<"请输入要删除的学生的id"<<std::endl;
    std::cin>>id;

    stuMager cStuMg;
    bool b = cStuMg.deleteStuById(v1,id);

    if (b)
    {
        std::cout<<"删除成功"<<std::endl;
    }
    else {
        std::cout<<"查无此人"<<std::endl;
    }

    getchar();
    system("clear");
    welcome();
    showMenu();

}

/* view层 更新一个学生 */
void   View:: updateByIdAtView(std::map<int, Student> & m1) {

    system("cls");

    std::cout<<"请输入要修改的学生的id"<<std::endl;
    int id = 0;
    std::cin>>id;
    std::string name = " ";

    std::cout<<"name:";
    std::cin>>name;

    int age = 0;
    std::cout<<"age:";
    std::cin>>age;

    Student cStu;
    cStu.setId(id);
    cStu.setName(name);
    cStu.setAge(age);

    stuMager cStuMg;

    Student cStu2 = cStuMg.updateStu(m1,cStu);

    if (cStu2.getId()!=-1)
    {
        std::cout<<cStu2<<std::endl;
        std::cout<<"修改成功"<<std::endl;
    }
    else
    {
        std::cout<<"查无此人"<<std::endl;
    }

    system("pause");
    system("cls");
    welcome();
    showMenu();

}

/* view层 把vec保存进文件 */
void   View:: saveToFileAtView(const std::map<int, Student> & m1, std::string pathName) {

    if (m1.begin()==m1.end()) {
        system("cls");
        std::cout<<"还没有任何学生信息，无法保存"<<std::endl;
    }
    else {
        // 保存
        stuMager cStuMg;
        bool b = cStuMg.saveToFile(m1,pathName);
        if (b) {
            system("clear");
            std::cout<<"保存成功"<<std::endl;
        }
        else  {
            std::cout<<"保存失败"<<std::endl;
        }
    }

    getchar();
    system("clear");
    welcome();
    showMenu();

}

/* view层 把文件中的东西导入 vec */
void  View::  readFromFileAtView(std::map<int, Student> & m, std::string pathName) {

    system("clear");

    stuMager cStuMg;
    bool b = cStuMg.readFromFile(m, std::move(pathName));
    if (b){
        std::cout<<"读取成功"<<std::endl;
    }
    else {
        std::cout<<"读取失败"<<std::endl;
    }
    getchar();
    system("clear");
    welcome();
    showMenu();
}
