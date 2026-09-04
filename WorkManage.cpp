#include <iostream>
#include "WorkManage.h"
#include "worker.h"

#include <fstream>

using namespace std;

void workerManage::Menu()
{
    cout << "----------------------" << endl;
    cout << "欢迎使用职工管理系统" << endl;
    cout << "----0.退出管理程序----" << endl;
    cout << "----1.增加职工信息----" << endl;
    cout << "----2.显示职工信息----" << endl;
    cout << "----3.删除离职职工----" << endl;
    cout << "----4.修改职工信息----" << endl;
    cout << "----5.查找职工信息----" << endl;
    cout << "----6.排序职工信息----" << endl;
    cout << "----7.清空所有数据----" << endl;
    cout << "----------------------" << endl;
}

workerManage::workerManage()
{
    this->ComNums = 0;
    this->w = NULL;
    int te_num = 0;

    int Department_ID;  // 部门编号
    string Personal_ID; // 职工编号
    string Name;        // 姓名
    string Job;

    ifstream ifs;
    ifs.open("User_information.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    while (ifs >> Personal_ID >> Name >> Department_ID >> Job)
    {
        te_num++;
    }
    ifs.close();
    ComNums = te_num;
    w = new worker *[ComNums];
    ifs.open("User_information.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "未找到该文件" << endl;
    }
    int j = 0;
    while (ifs >> Personal_ID >> Name >> Department_ID >> Job)
    {
        worker *p;
        p = NULL;
        if (Department_ID == 1)
        {
            p = new Employee(Personal_ID, Name, Job);
        }
        else if (Department_ID == 2)
        {
            p = new Manager(Personal_ID, Name, Job);
        }
        else if (Department_ID == 3)
        {
            p = new Boss(Personal_ID, Name, Job);
        }
        w[j] = p;
        j++;
    }
}

void workerManage::Addinfo()
{
    int nums, department_id;
    string te_ID, te_name, te_job;

    cout << "输入要增加的员工人数：";
    cin >> nums;
    if (nums > 0)
    {
        int newnum = ComNums + nums; // 现在的总人数
        worker **newspace = new worker *[newnum];

        if (w != NULL)
        {
            for (int i = 0; i < ComNums; i++)
            {
                newspace[i] = w[i];
            }
        }

        for (int i = 0; i < nums; i++)
        {
            cout << "请输入第 " << i + 1 << " 个员工的部门编号(1.普通员工 2.经理 3.老板)：";
            cin >> department_id;

            cout << "输入员工的职工编号：";
            cin >> te_ID;

            cout << "输入员工的姓名：";
            cin >> te_name;

            cout << "输入员工的职位：";
            cin >> te_job;

            worker *new_worker = NULL;
            if (department_id == 1)
            {
                new_worker = new Employee(te_ID, te_name, te_job);
            }
            else if (department_id == 2)
            {
                new_worker = new Manager(te_ID, te_name, te_job);
            }
            else if (department_id == 3)
            {
                new_worker = new Boss(te_ID, te_name, te_job);
            }
            newspace[ComNums + i] = new_worker;
        }
        delete[] w;
        w = newspace;
        ComNums = newnum;
        cout << "成功添加了 " << nums << "名员工" << endl;
        cout << "现在公司一共有 " << ComNums << "名" << "员工" << endl;
    }
}

void workerManage::Save()
{
    ofstream ofs;
    ofs.open("User_information.txt", ios::out);

    for (int i = 0; i < ComNums; i++)
    {
        ofs << w[i]->getPersonal_ID() << " "
            << w[i]->getName() << " "
            << w[i]->getDepartment_ID() << " "
            << w[i]->getJob() << endl;
    }
    ofs.close();
}

void workerManage::Showinfo()
{
    int Department_ID;  // 部门编号
    string Personal_ID; // 职工编号
    string Name;        // 姓名
    string Job;
    ifstream ifs;

    if (ComNums == 0)
    {
        cout << "当前公司没有员工，请添加员工信息" << endl;
    }
    else
    {
        for (int i = 0; i < ComNums; i++)
        {

            cout << "第" << i + 1 << "名员工的信息：" << endl;
            cout << "部门编号：" << w[i]->getDepartment_ID() << "  " << "职工编号：" << w[i]->getPersonal_ID() << endl;
            cout << "姓名：" << w[i]->getName() << "  " << "职务：" << w[i]->getJob() << endl;

            cout << "工作内容是：";
            w[i]->duty();
        }
    }
}

int workerManage::Find_person()
{
    string target_personnal_ID;
    int index = 0;
    cout << "输入员工的编号：";
    cin >> target_personnal_ID;
    for (int i = 0; i < ComNums; i++)
    {
        if (target_personnal_ID == w[i]->getPersonal_ID())
        {
            return i;
        }
    }
    cout << "未找到该名员工" << endl;
    return -1;
}

void workerManage::Delete_person()
{
    int index = Find_person();
    if (index == -1)
    {
        return;
    }
    else
    {
        for (int j = index; j < ComNums - 1; j++)
        {
            w[j] = w[j + 1];
        }
    }
    ComNums--;
    cout << "现在公司一共有 " << ComNums << "名" << "员工" << endl;
}

void workerManage::Update_person()
{
    int index = Find_person();
    int Department_ID;
    string Personal_ID;
    string Name;
    string Job;
    worker *new_worker;
    new_worker = NULL;
    if (index == -1)
    {
        return;
    }
    else
    {
        delete w[index];
        w[index] = NULL;

        cout << "输入该员工修改后的信息：";
        cout << "新部门编号：";
        cin >> Department_ID;
        cout << "新职工编号：";
        cin >> Personal_ID;
        cout << "姓名：";
        cin >> Name;
        cout << "新职务：";
        cin >> Job;

        if (Department_ID == 1)
        {
            new_worker = new Employee(Personal_ID, Name, Job);
        }
        else if (Department_ID == 2)
        {
            new_worker = new Manager(Personal_ID, Name, Job);
        }
        else if (Department_ID == 3)
        {
            new_worker = new Boss(Personal_ID, Name, Job);
        }
        w[index] = new_worker;
    }
}

void workerManage::Search_person()
{
    cout << "你正在查找职工：" << endl;
    int is_find = Find_person();
    if (is_find != -1)
    {
        cout << "该名职工的信息是：" << endl;
        cout << "部门编号：" << w[is_find]->getDepartment_ID() << "    职工编号：" << w[is_find]->getPersonal_ID() << endl;
        cout << "姓名：" << w[is_find]->getName() << "  职位：" << w[is_find]->getJob() << endl;
        cout << "工作内容是：";
        w[is_find]->duty();
    }
}

void workerManage::Sort_person()
{
    worker *temp_person;
    for (int i = 0; i < ComNums; i++)
    {
        for (int j = 0; j < ComNums - i - 1; j++)
        {
            if (w[j]->getPersonal_ID() > w[j + 1]->getPersonal_ID())
            {
                temp_person = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp_person;
            }
        }
    }
    cout << "排序完成!!!  顺序由低到高" << endl;
}

void workerManage::Clearinfo()
{
    int option = 0;
    cout << "确定要清空所有数据吗？(1. 确认清空  2. 返回菜单)" << endl;
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < ComNums; i++)
        {
            if (w[i] != NULL)
            {
                delete w[i];
                w[i] = NULL;
            }
        }
        delete[] w;
        w = NULL;
        ComNums = 0;

        ofstream ofs("User_information.txt", ios::trunc);
        ofs.close();
    }
    else
    {
        return;
    }
}
