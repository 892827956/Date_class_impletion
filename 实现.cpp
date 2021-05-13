#include<iostream>
#include "date.h"
Date::Date(int ndays)
{
	if (ndays == 0)
		yr = mo = day = 0;
	else
	{
		day = ndays;
		yr = 1;
		//步骤一
		while (1)
		{
			int  n = Leapyear(yr) ?366 : 365;
			yr = 1;
			if (day <= n)
				break;
			day -= n;
			++yr;
		}	//并在这里求出这个day的值
		//在上面这个循环  找到对应的年份
		//下面就开始减去day  并且获得月份
		for (mo = 1; mo < 13; mo++)
		{
			int n = dys[mo - 1];
			if (mo == 2 || Leapyear(yr))
				n++;
			if (day <= n)
				break;
			day -= n;
		}
	}
}

Date & Date::operator = (int ndays)
{
	if (ndays == 0)
		yr = mo = day = 0;
	else
	{
		day = ndays;
		yr = 1;
		//步骤一
		while (1)
		{
			int  n = Leapyear(yr) ? 366 : 365;
			yr = 1;
			if (day <= n)
				break;
			day -= n;
			++yr;
		}	//并在这里求出这个day的值
		//在上面这个循环  找到对应的年份
		//下面就开始减去day  并且获得月份
		for (mo = 1; mo < 13; mo++)
		{
			int n = dys[mo - 1];
			if (mo == 2 || Leapyear(yr))
				n++;
			if (day <= n)
				break;
			day -= n;
		}
	}

	return *this;
}
//和转换构造函数和转换赋值函数的方向相反
Date :: operator long()const
{
	long ndays = 0;
	for (int i = 1; i < yr; i++)
		ndays += Leapyear(yr) ? 366 : 365;
	for (int i = 1; i < mo; i++)
		ndays += dys[i - 1];
	//把所有的月份算完以后  在这里再加上一个判断闰年的数
	if (mo > 2 && Leapyear(yr))
		++ndays;
	ndays += day;
	return ndays;
}

//下面是自增自减的定义
Date& Date::operator++()
{
	long ndays = *this;//利用转换构造函数，转换为一个常整型
	++ndays;
	*this = ndays;//秀啊  再利用转换赋值函数
	return *this;
}
