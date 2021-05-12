#pragma once
#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	int yr, mo, day;
	static const int dys[];//静态成员数据，平年所对应每月的天数
	bool Leapyear(int y)const//闰年判断
	{
		return (y % 4 == 0 && y % 100) || (y % 400 == 0);//看清楚这里的闰年判断的方法   其实就是数字的逻辑
	}

public:
	Date() { yr = mo = day = 0; }//默认构造函数
	Date(int y,int m,int d):yr(y),mo(m),day(d){}//普通构造函数
	Date(const Date& dt)//COPY构造函数
	{
		yr = dt.yr;
		mo = dt.mo;
		day = dt.day;
	}
	Date(int ndays);//转换构造函数
	~Date() {}//析构函数
	//赋值运算符重载
	Date& operator = (const Date & dt)//COPY赋值函数
	{
		yr = dt.yr;
		mo = dt.mo;
		day = dt.day;

		return *this;
	}
	Date & operator = (int ndays);//转换赋值函数
	//成员转换
	operator long()const;//成员转换函数   记住这个名字。其返回的就是这个int
	//闰年判断（判断自身）
	bool Leapyear()const
	{
		return  Leapyear(yr);
	}
	//自增自减的运算符合复合赋值运算符
	Date & operator ++();//前++
	Date & operator ++(int);//后++
	Date & operator --();//前--
	Date & operator --(int);//后--
	Date& operator+=(int n);//Date+=n
	Date& operator-=(int n);//Date-=n

	//数据成员取值和赋值
	int Get_year()const { return yr; }
	int Get_month()const { return mo; }
	int Get_day()const { return day; }
	void Set_year(int n) { yr = n; }
	void Set_month(int n) { mo = n; }
	void Set_day(int n) { day = n; }

	//输出
	void display()const { std::cout << yr << "/" << mo << "/" << day << std::endl; }
	friend istream&operator >>(istream & input, Date & dt);//对这个dt赋值
	friend ostream&operator <<(ostream & output, Date & dt);

};
#endif
