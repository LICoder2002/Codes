#pragma once //防止头文件重复包含
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

#include<fstream>
#define FILENAME "empFile.txt"

//管理类
//负责内容：
//1、与用户沟通的菜单界面
//2、对职工增删改查的操作
//3、与文件的读写交互

class WorkerManager
{
public:

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//判断文件是否为空 标志
	bool m_FileIsEmpty;

	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//添加员工
	void ADD_Emp();

	//保存文件
	void save();

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//展示员工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//按照员工编号判断职工是否存在，如果存在返回职工在数组中的位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void mod_Emp();

	//查找职工 
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//清空数据
	void Clean_File();

	//析构函数
	~WorkerManager();

};
