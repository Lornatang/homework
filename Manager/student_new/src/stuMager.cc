//
// Created by mac on 2018/8/26.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "../include/Student.h"
#include "../include/stuMager.h"

using namespace std;

stuMager::stuMager() {}

stuMager::~stuMager() {}

// 增
Student stuMager:: addAStu(map<int,Student> & m1,Student & stu) {

    // 先假设id可以重复了
    m1.insert(make_pair(stu.getId(),stu));
    return stu;
}

// 删
bool  stuMager:: deleteStuById(map<int, Student> & m1, const int & id) {

    bool b = false;

    map<int,Student> ::iterator iter;
    iter = m1.find(id);
    if (iter!=m1.end())
    {
        m1.erase(iter);
        b = true; // 删除成功
    }

    return b;
}

// 改
Student stuMager:: updateStu(map<int,Student> & m1,const Student & cStu) {

    // 迭代器是一个smart point！
    // 是可以通过迭代器去访问到 m1里的东西，并且做出修改的！
    // 除非迭代器是const迭代器

    Student stu = Student();
    int id = cStu.getId();

    map<int,Student> :: iterator iter;
    iter = m1.find(id);
    if (iter!=m1.end()) {
        // 修改
        iter->second = cStu;
        stu = cStu; // 把修改后的对象，赋值，再返回上层
    }

    return stu;
}

// 查 by id
Student  stuMager:: findById(const map <int, Student> & m1, const int & id) const{

    Student stu = Student();

    map<int,Student> ::const_iterator iter;
    iter = m1.find(id);
    if (iter!=m1.end()) {
        stu = iter->second;
    }

    return stu;
}

// showAll
void  stuMager:: showAll(const map<int,Student> & m1) const{

    for (auto p : m1) {
        cout<<p.second<<endl;
    }

}

// save to file
bool stuMager::saveToFile(const map <int,Student> & m1,const string & pathName) const{

    bool b = true;

    //fstream ofs(pathName,ios::out+ios::binary); // 为什么不是以binary保存？
    fstream ofs(pathName,ios::out);
    if (ofs) {
        stringstream ss;

        cout<<"文件打开"<<endl;

        Student stu;
        for (auto p = m1.begin();p!=m1.end();p++)
        {
            stu = p->second;
            ss<<stu<<endl;
        }

        ofs<<ss.str(); // 注意，输出一定是 ss.str();

        ofs.close();
    }
    else {
        cout<<"文件打开失败"<<endl;
        b = false;
    }

    return b;
}


// read from file
bool stuMager:: readFromFile(std::map<int,Student> & m1, std::string path) {
    bool b = true;

    m1.clear(); // 清掉原来的

    fstream fs(path,ios::in);
    if (fs) {
        cout<<"文件打开"<<endl;
        string s;
        stringstream ss;
        while (getline(fs,s)) {
            Student cStu;
            ss<<s;
            ss>>cStu;
            ss.clear();

            m1.insert(make_pair(cStu.getId(),cStu));

        }
        fs.close();

    }
    else {
        cout<<"文件打开失败"<<endl;
        b = false;
    }

    return b;
}
