#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工类：普通员工、经理、老板

//将三种职工抽象到一个类（woker）中，利用多态管理不同的职工种类

//职工抽象类
class Worker
{
public:

	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;
	
	int m_ID;//职工编号
	string m_Name;//职工姓名
	int m_DeptID;//部门编号

};