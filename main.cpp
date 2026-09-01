#include <iostream>
#include "WorkManage.h"
#include "worker.h"
using namespace std;

int main(void)
{
    workerManage wm;
    wm.manu();
    int choice = 0;
    while (1)
    {
        cout << "请输入你的选择：";
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出程序
            cout << "已退出管理程序" << endl;
            exit(0);
        case 1: // 增加职工
            wm.Addinfo();
            wm.Save();
            break;
        case 2: // 显示职工信息
            wm.Showinfo();
            break;
        case 3: // 删除职工信息
            break;
        case 4: // 修改职工信息
            break;
        case 5: // 查找职工信息
            break;
        case 6: // 给职工信息排序
            break;
        case 7: // 清空所有文档
            break;
        }
    }

    return 0;
}
