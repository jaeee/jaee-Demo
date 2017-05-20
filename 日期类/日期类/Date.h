
#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	:_year(year)
	, _month(month)
	, _day(day)
	{
		if (InvalidDate())
		{
			//cout << "ERROR" << endl;
			_year = year;
			_month = month;
			_day = day;
		}
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()
	{}

public:
	void display()
	{
		cout << _year << "-" << _month << "-" << "day" << endl;
	}
	friend ostream& operator<<(ostream& out, Date& d);//重载<<
	friend istream& operator>>(istream& in, Date& d);//重载>>
	Date operator+(int day)//日期对象加上一个天数
	{
		_day += day;

		while (_day > DayInMonth())
		{
			_day -= DayInMonth();
			_month++;
		}
		if (_month > 12)
		{
			_month -= 12;
			_year++;
		}
		return *this;
	}
	Date operator-(int day)//日期对象减上一个天数
	{
		_day -= day;
		while (_day)
		{
			if (_day < 0)
			{
				//_day = 0 - _day;
				_month--;
				int temp = DayInMonth();
				_day = temp - (-_day);
				if (_month == 1)
				{
					_month = 12;
					_year--;
				}
			}
		}
		return *this;
	}
	int  operator-(Date  d)//两个日期对象相减求天数
	{
		int Day = 0;
		Date Temp = *this;
		if (*this > d)
		{
			while (_day > d._day)
			{
				d++;
				Day++;
			}
		}
		else
		{
			while (*this < d)
			{
				Temp++;
				Day++;
			}
		}
		return Day;
	}
	Date& operator++()//日期前置++
	{
		return *this + 1;
	}
	Date operator++(int)//日期后置++
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;

	}
	Date AddOne(const Date& d)//日期加一天
	{
		Date temp(d);
		temp._day += 1;
		return temp;
	}
	Date& operator+=(int day)//日期对象加等
	{
		*this = *this + day;
		return *this;
	}
	Date& operator-=(int day)//日期对象减等
	{
		*this = *this - day;
		return *this;
	}
	
	bool operator<(const Date& d)//比较*this对象是否比d日期对象小
	{
		if ((_year < d._year) && (_month < d._month) && (_day<d._day))
			return true;
		return false;
	}
	bool operator>(const Date& d)//比较*this对象是否比d日期对象大
	{
		if ((_year > d._year) && (_month > d._month) && (_day>d._day))
			return true;
		return false;
	}
	bool operator==(const Date& d)//比较*this对象与d日期对象是否相等
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return true;
		return false;
	}
	bool operator<=(const Date& d)//比较*this对象是否比d日期对象小于等于
	{
		if ((_year <= d._year) && (_month <= d._month) && (_day<=d._day))
			return true;
		return false;
	}
	bool operator>=(const Date& d)//比较*this对象是否比d日期对象大于等于
	{
		if ((_year >= d._year) && (_month >= d._month) && (_day>=d._day))
			return true;
		return false;
	}

public:
	//判断输入日期是否合法
	bool InvalidDate()
	{
		if (_year < 1900 || _month<1 || _month>12 || _day<1 || _day>DayInMonth())
		{
			return true;
		}
		return false;
	}
	//判断月份天数
	int DayInMonth()
	{
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (IsLeapYear())
		{
			arr[2] = 29;
		}
		return arr[_month];
	}
	//判断闰年
	bool IsLeapYear()
	{
		if ((_year % 400 == 0) || ((_year % 4 == 0) && (_year % 100 != 0)))
		{
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, Date& d)//重载<<
{
	d.display();
	return out;
}
istream& operator>>(istream& in, Date& d)//重载>>
{
	cin >> d._year >> d._month >> d._day;
	return in;
}


