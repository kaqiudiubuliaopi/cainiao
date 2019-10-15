/*************************************************
** 功能 : tringle_Demo  
** 作者 : kaqiudiubuliaopi
** 版本 : 2019-8-30 / 20:00
** 版权 : GNU General Public License(GNU GPL)
/**************************************************/

#include <iostream>
#include <math.h>
using namespace std;
class tringle_demo
{
public:
	bool juage_tringle(float a,float b,float c);
	double girth(float a, float b, float c);
	double area(float a, float b, float c);
	void judge_class(float a, float b, float c);
private:float a;
		float b;
		float c;
};

/*----------------------------------*
         Class Definition
*-----------------------------------*/
bool tringle_demo::juage_tringle(float a, float b, float c)
{
	if (a + b < c&&a + c < b&&b + c < a)
		return false;
	else return true;
}
double tringle_demo::girth(float a, float b, float c)
{
	double m;
	m = a + b + c;
	return m;
}
double tringle_demo::area(float a, float b, float c)
{
	double n;
	n = sqrt((a + b + c)*(a + b - c)*(a + c - b)*(b + c - a));
	return n;
}
void tringle_demo::judge_class(float a, float b, float c)
{
	int t;
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b*b + c * c < a*a)
		cout << "三角形为钝角三角形";
	else if (b*b + c * c == a * a)
		cout << "三角形为直角三角形";
	else if (b*b + c * c > a*a)
		cout << "三角形为锐角三角形";
}


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	tringle_demo t;
	float a,b,c;
	double m, n;
	cout << "请输入三角形的三边长："<<endl;
	cin >> a >> b >> c;
	cout<<"是否为三角形"<<t.juage_tringle(a,b,c)<<endl;
    m=t.girth(a,b,c);
	cout <<"三角形的周长"<< m << endl;
	n=t.area(a,b,c);
	cout <<"三角形的面积为"<<n << endl;
	t.judge_class(a,b,c);
	system("pause");

	return 0;


}
