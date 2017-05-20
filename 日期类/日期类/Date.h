
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
	friend ostream& operator<<(ostream& out, Date& d);//����<<
	friend istream& operator>>(istream& in, Date& d);//����>>
	Date operator+(int day)//���ڶ������һ������
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
	Date operator-(int day)//���ڶ������һ������
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
	int  operator-(Date  d)//�������ڶ������������
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
	Date& operator++()//����ǰ��++
	{
		return *this + 1;
	}
	Date operator++(int)//���ں���++
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;

	}
	Date AddOne(const Date& d)//���ڼ�һ��
	{
		Date temp(d);
		temp._day += 1;
		return temp;
	}
	Date& operator+=(int day)//���ڶ���ӵ�
	{
		*this = *this + day;
		return *this;
	}
	Date& operator-=(int day)//���ڶ������
	{
		*this = *this - day;
		return *this;
	}
	
	bool operator<(const Date& d)//�Ƚ�*this�����Ƿ��d���ڶ���С
	{
		if ((_year < d._year) && (_month < d._month) && (_day<d._day))
			return true;
		return false;
	}
	bool operator>(const Date& d)//�Ƚ�*this�����Ƿ��d���ڶ����
	{
		if ((_year > d._year) && (_month > d._month) && (_day>d._day))
			return true;
		return false;
	}
	bool operator==(const Date& d)//�Ƚ�*this������d���ڶ����Ƿ����
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return true;
		return false;
	}
	bool operator<=(const Date& d)//�Ƚ�*this�����Ƿ��d���ڶ���С�ڵ���
	{
		if ((_year <= d._year) && (_month <= d._month) && (_day<=d._day))
			return true;
		return false;
	}
	bool operator>=(const Date& d)//�Ƚ�*this�����Ƿ��d���ڶ�����ڵ���
	{
		if ((_year >= d._year) && (_month >= d._month) && (_day>=d._day))
			return true;
		return false;
	}

public:
	//�ж����������Ƿ�Ϸ�
	bool InvalidDate()
	{
		if (_year < 1900 || _month<1 || _month>12 || _day<1 || _day>DayInMonth())
		{
			return true;
		}
		return false;
	}
	//�ж��·�����
	int DayInMonth()
	{
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (IsLeapYear())
		{
			arr[2] = 29;
		}
		return arr[_month];
	}
	//�ж�����
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

ostream& operator<<(ostream& out, Date& d)//����<<
{
	d.display();
	return out;
}
istream& operator>>(istream& in, Date& d)//����>>
{
	cin >> d._year >> d._month >> d._day;
	return in;
}


