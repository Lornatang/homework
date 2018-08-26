//
// Created by mac on 2018/8/26.
//

#include "../include/utils.hpp"

void menu()
{
    cout << "请按任意将进入学生管理系统:" << endl;
    getchar();
    system("clear");

    cout << "================================================================================\n\n";
    cout << "------------------------ 请选择要操作的命令：-----------------------------------\n\n";
    cout << "-------------------------- 1 输入学生信息--------------------------------------\n\n";
    cout << "-------------------------- 2 输出学生信息--------------------------------------\n\n";
    cout << "-------------------------- 3 删除学生信息--------------------------------------\n\n";
    cout << "-------------------------- 4 查找学生信息--------------------------------------\n\n";
    cout << "-------------------------- 5 修改学生信息--------------------------------------\n\n";
    cout << "-------------------------- 6 将学生的语文成绩按从大到小排----------------------\n\n";
    cout << "-------------------------- 7 将学生的数学成绩按从大到小排----------------------\n\n";
    cout << "-------------------------- 8 将学生的英语成绩按从大到小排----------------------\n\n";
    cout << "-------------------------- 9 将学生的总成绩按从大到小排------------------------\n\n";
    cout << "================================================================================\n\n";

    int Item; //操作命令

    Student st{}; //学生对象

    bool Flag = true;

    while (Flag)
    {
        cout << "请选择操作命令:";
        cin >> Item;

        switch (Item)
        {
        // 输入学生信息
        case 1:
        {
            st.InputStudent();
        }
        break;
            // 输出学生信息
        case 2:
        {
            st.OutputStudent();
        }
        break;
            // 删除学生信息
        case 3:
        {
            st.DeleteStudent();
        }
        break;

            //查找学生信息
        case 4:
        {
            st.SearchStudent();
        }
        break;

        case 5:
        {
            st.ChangeStudent();
        }
        break;

        case 6:
        {
            st.ScortByChinese();
            st.OutputStudent();
        }
        break;

        case 7:
        {
            st.ScortByMath();
            st.OutputStudent();
        }
        break;

        case 8:
        {
            st.ScortByEnglish();
            st.OutputStudent();
        }
        break;

        case 9:
        {
            st.ScortByTotal();
            st.OutputStudent();
        }
        break;
        case 0:
        {
            Flag = false;
            break;
        }
        default:
        {
            cout << "input error. Again input." << endl;
        }
        break;
        }
    }
}
int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
