#define  _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<windows.h>
using namespace std;
int ifr(int a)
{
	if (((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0))
		return 1;
	else
		return 0;
}
int Getday(int &a, int &b, int &c)
{
	int s=c,i;
	if(ifr)
	{
		for (i = 0; i < b; i++)
		{
		if (i==1||i==3||i==5||i==7||i==8||i==10)
		{
			s +=31;
		}
		if ( i == 4 || i == 6 || i == 9 || i == 11 )
		{
			s += 30;
		}
		if (i == 2)
		{
			s += 29;
		}
		}
		
	}
	else 
	{
		for (i = 0; i <b; i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
			{
				s += 31;
			}
			if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				s += 30;
			}
			if (i == 2)
			{
				s += 28;
			}
		}
	}
	return s;
}
void Getweek(int &t)
{
	float w;
	
	w =(double)t / 7+1;
	printf("��һ���Ǹ���ĵ�%.0f��", w);
}
int main()
{
	int y, m, d;
	int t;
	printf("�����������գ���ʽ����-��-�գ���\n");
	scanf("%d-%d-%d", &y, &m, &d);
	t=Getday(y, m, d);
	printf("��һ���Ǹ���ĵ�%d��\n",t);
	Getweek(t);
	system("pause");
}