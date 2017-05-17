#include"Complex.h"

int main()
{
	Complex d1(5, 10);
	Complex d2(7, 10);
	Complex d4;

	cout << "d1(5,10)  "<<"d2(7,10)  "<<"d4(0,0)"<<endl;
	
	cout << "d4 = d1" << endl;
	d4 = d1;
	d4.Display();
	cout << "d2 - d1" << endl;
	d4 = d2 - d1;
	d4.Display();
	cout << "d2 + d1" << endl;
	d4 = d2 + d1;
	d4.Display();
	cout << "d4 += d1" << endl;
	d4 += d1;
	d4.Display();
	cout << "d4 -= d1" << endl;
	d4 -= d1;
	d4.Display();
	cout << "d4++" << endl;
	d4++;
	d4.Display();
	cout << "++d4" << endl;
	++d4;
	d4.Display();
	cout << "d4++" << endl;
	d4--;
	d4.Display();
	cout << "--d4" << endl;
	--d4;
	cout << "d4 == d1" << endl;
	cout << (d4 == d1) << endl;

	system("pause");
	return 0;
}