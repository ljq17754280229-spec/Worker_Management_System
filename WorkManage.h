#pragma once
#include "worker.h"

class workerManage
{
public:
    void Menu();            // 打印菜单
    void Addinfo();         // 增加员工信息
    workerManage();         // 初始化
    void Save();            // 保存到文件里
    void Showinfo();        // 显示职工信息
    void Delete_person();   // 删除员工信息
    void Update_person();   // 修改职工信息
    int Find_person();     // 按照编号寻找职工
private:
    int ComNums;            // 公司总人数
    worker **w;             // 存储父类指针的数组

};