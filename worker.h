#pragma once
#include <string>
#include <iostream>
using namespace std;

class worker // 父类
{
protected:
    int Department_ID;  // 部门编号
    string Personal_ID; // 职工编号
    string Name;        // 姓名
    string Job;         // 工作岗位
public:
    virtual void duty() = 0; // 责任函数
    int getDepartment_ID()
    {
        return Department_ID;
    }
    string getPersonal_ID()
    {
        return Personal_ID;
    }
    string getName()
    {
        return Name;
    }
    string getJob()
    {
        return Job;
    }
};

class Employee : public worker
{
public:
    void duty() override
    {
        cout << "完成经理下发的任务" << endl;
    }
    Employee(string te_ID, string te_name, string te_job)
    {
        this->Personal_ID = te_ID;
        this->Name = te_name;
        this->Job = te_job;
        this->Department_ID = 1;
    }
};

class Manager : public worker
{
public:
    void duty() override
    {
        cout << "完成老板交给的任务，并下发任务给员工" << endl;
    }
    Manager(string te_ID, string te_name, string te_job)
    {
        this->Personal_ID = te_ID;
        this->Name = te_name;
        this->Job = te_job;
        this->Department_ID = 2;
    }
};

class Boss : public worker
{
public:
    void duty() override
    {
        cout << "管理公司所有事务" << endl;
    }
    Boss(string te_ID, string te_name, string te_job)
    {
        this->Personal_ID = te_ID;
        this->Name = te_name;
        this->Job = te_job;
        this->Department_ID = 3;
    }
};