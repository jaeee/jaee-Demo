#include<iostream>;
using namespace std;

class Complex
{
public:
	Complex(int real=0, int image=0)
		:_real(real)
		, _image(image)
	{}

	~Complex()
	{}

	Complex(Complex& com)
		:_real(com._real)
		,_image(com._image)
	{}

	//运算符重载
	Complex& operator=(const Complex& d)//赋值
	{
		_real = d._real;
		_image = d._image;
		return *this;
	}
	bool operator ==(const Complex& d)//判断相等
	{
		return (_real == d._real) && (_image == d._image);
	}
	Complex operator+(const Complex& d)//复数相加
	{
		Complex temp(0, 0);
		temp._real = _real + d._real;
		temp._image = _image + d._image;
		return temp;
	}
	//Complex& operator+(const Complex& d)//复数相加
	//{
	//	_real=_real+d._real;
	//	_image = _image + d._image;
	//	return *this;
	//}
	Complex& operator+=(const Complex& d)  //复数对象+=d
	{
		_real += d._real;
		_image += d._image;
		return *this;
	}
	Complex operator-(const Complex& d)  //两个复数相减  
	{
		Complex temp(0, 0);
		temp._real = _real - d._real;
		temp._image = _image - d._image;
		return temp;
	}
	Complex& operator-=(const Complex& d)  //复数对象-=d
	{
		_real -= d._real;
		_image -= d._image;
		return *this;
	}
	Complex operator++()  //前置++
	{
		_real++;
		_image++;
		return *this;
	}
	Complex operator++(int)  //后置++  且不用添加参数  特殊形式
	{
		Complex temp = *this;
		_real++;
		_image++;
		return temp;
	}
	Complex operator--() //前置--
	{
		_real--;
		_image--;
		return *this;
	}
	Complex operator--(int)  //后置--
	{
		Complex temp = *this;
		_real--;
		_image--;
		return temp;
	}
	void Display()  //显示复数的实部和虚部
	{
		cout << "real:" << _real << endl;
		cout << "image:" << _image << endl;
	}
private:
	int _real;
	int _image;
};