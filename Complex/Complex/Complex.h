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

	//���������
	Complex& operator=(const Complex& d)//��ֵ
	{
		_real = d._real;
		_image = d._image;
		return *this;
	}
	bool operator ==(const Complex& d)//�ж����
	{
		return (_real == d._real) && (_image == d._image);
	}
	Complex operator+(const Complex& d)//�������
	{
		Complex temp(0, 0);
		temp._real = _real + d._real;
		temp._image = _image + d._image;
		return temp;
	}
	//Complex& operator+(const Complex& d)//�������
	//{
	//	_real=_real+d._real;
	//	_image = _image + d._image;
	//	return *this;
	//}
	Complex& operator+=(const Complex& d)  //��������+=d
	{
		_real += d._real;
		_image += d._image;
		return *this;
	}
	Complex operator-(const Complex& d)  //�����������  
	{
		Complex temp(0, 0);
		temp._real = _real - d._real;
		temp._image = _image - d._image;
		return temp;
	}
	Complex& operator-=(const Complex& d)  //��������-=d
	{
		_real -= d._real;
		_image -= d._image;
		return *this;
	}
	Complex operator++()  //ǰ��++
	{
		_real++;
		_image++;
		return *this;
	}
	Complex operator++(int)  //����++  �Ҳ�����Ӳ���  ������ʽ
	{
		Complex temp = *this;
		_real++;
		_image++;
		return temp;
	}
	Complex operator--() //ǰ��--
	{
		_real--;
		_image--;
		return *this;
	}
	Complex operator--(int)  //����--
	{
		Complex temp = *this;
		_real--;
		_image--;
		return temp;
	}
	void Display()  //��ʾ������ʵ�����鲿
	{
		cout << "real:" << _real << endl;
		cout << "image:" << _image << endl;
	}
private:
	int _real;
	int _image;
};