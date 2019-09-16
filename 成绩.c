#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#define MAX 100
typedef struct student
{
	char name[10];
	char number[10];
	float dailyScore;
	float finalScore;
	float generalScore;
}SS;
void ReadData(SS stu[], int N)//录入学生成绩
{
	SS* readDataFromFile(int *N);
	for (int i = 0; i < N; i++)
	{
		printf("学号  姓名  平时成绩  期末成绩\n");
		scanf("%s%s%f%f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf('\n');
	}
}
void calcuScore(SS stu[], int N)//计算每个学生的总成绩
{
	for (int i = 0; i < N; i++)
	{
		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* 学号：%s	姓名:%s		总成绩:%f分\n", (stu[i].number), (stu[i].name), stu[i].generalScore);
	}
	getchar();
}
SS* readDataFromFile(int *N)//从文件中读入学生成绩
{
	SS *stu;
	FILE *fp = NULL;
	int count = 0;
	int i = 0;
	fp = fopen("data.txt", "r");
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the file 'data.txt'\n");
		getchar();
	}
	printf("学生数目为:%d\n", count);
	stu = (SS*)malloc(count * sizeof(SS));
	while ((!feof(fp)))
	{
		fscanf(fp, "%s%s%f%f\n", (stu[i].number), (stu[i].name), &stu[i].dailyScore, &stu[i].finalScore);
		printf("* 学号：%s	姓名:%s		平时成绩：%f分		期末成绩:%f分\n", (stu[i].number), (stu[i].name), stu[i].dailyScore, stu[i].finalScore);

		i++;
	}

	getchar();

	fclose(fp);

	return stu;
}
int paiming(const void *a, const void *b)
{
	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);
	if ((*aa).generalScore < (*bb).generalScore)  
		return 1;
	else if ((*aa).generalScore > (*bb).generalScore) 
		return -1;
}

void sortScore(SS stu[], int N)
{
	qsort(&(stu[0]), N, sizeof(stu[0]), paiming);//C语言编译器函数库自带的快速排序函数; 是stu所指数组进行排序
}
void printOut(SS stu[], int N)
{
	for (int i = 0; i < N; i++)
	{

		printf("第%d名信息 学号：%s	姓名:%s		总成绩:%f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}
void search(SS stu[], int N, char *id)
{
	int i;

	for (i = 0; i < N; i++)
		if (strcmp(stu[i].number, id) == 0)
		{
			printf("* 学号：%s	姓名:%s		平时成绩：%f分		期末成绩:%f分\n", (stu[i].number), (stu[i].name), stu[i].dailyScore, stu[i].finalScore);

			return 0;
		}
	printf("没找到相应记录\n");
}
void Analyze(SS stu[], int N)//4.班级成绩分析
{
	float sum_1 = 0, sum_2 = 0,AVG = 0, VAR = 0;
	for (int i = 0; i < N; i++)
	{
		sum_1 += stu[i].generalScore;
	}
	AVG = sum_1 / N;
	printf("班级成绩平均值为%f\n", AVG);
	for (int i = 0; i < N; i++)
	{
		sum_2 += (stu[i].generalScore - AVG)*(stu[i].generalScore - AVG);
	}
	VAR = sum_2 / N;
	printf("班级成绩方差为%f\n", VAR);
	getchar();
}
int main()
{
	int N=0, i,n=0;
	char id[10];
	SS  *pstu = NULL;   
	//ReadData(pstu, N);
	pstu = readDataFromFile(&N);
	calcuScore(pstu, N);
	sortScore(pstu, N);
	printOut(pstu, N);
	printf("输入要查询的学号：");
	scanf("%s", &id);
	search(pstu,N,id);
	Analyze(pstu, N);
	free(pstu);
	system("pause");
}
