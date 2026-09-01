#pragma once
#include "worker.h"

class workerManage
{
public:
    void manu();        // 打印菜单
    void Addinfo();     // 增加员工信息
    workerManage();     // 初始化
    void Save();        // 保存到文件里
    void Showinfo();    // 显示职工信息
private:
    int ComNums;        // 公司总人数
    worker **w;         // 存储父类指针的数组

};