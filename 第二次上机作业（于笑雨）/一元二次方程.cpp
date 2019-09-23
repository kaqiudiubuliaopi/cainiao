#include <iostream>
#include<math.h>
#define f(x) ax^2+bx+c
using namespace std;
int main()
{
	int a, b, c;
	int x1,x2;
	cout << "请输入一元二次方程系数a,b,c的值：" << endl;
	cin >> a >> b >> c;
	if (b*b - 4 * a*c < 0)
		cout << "无实根" << endl;
	else if (b*b - 4 * a*c >= 0)
	{
		x1 = (-b + sqrt(b*b - 4 * a*c)) / 2 * a;
		x2 = (-b - sqrt(b*b - 4 * a*c)) / 2 * a;
	}
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
	system("pause");

	return 0;


}