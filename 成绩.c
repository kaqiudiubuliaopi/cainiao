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
void ReadData(SS stu[], int N)//¼��ѧ���ɼ�
{
	SS* readDataFromFile(int *N);
	for (int i = 0; i < N; i++)
	{
		printf("ѧ��  ����  ƽʱ�ɼ�  ��ĩ�ɼ�\n");
		scanf("%s%s%f%f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf('\n');
	}
}
void calcuScore(SS stu[], int N)//����ÿ��ѧ�����ܳɼ�
{
	for (int i = 0; i < N; i++)
	{
		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* ѧ�ţ�%s	����:%s		�ܳɼ�:%f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);
	}
	getchar();
}
SS* readDataFromFile(int *N)//���ļ��ж���ѧ���ɼ�
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
	printf("ѧ����ĿΪ:%d\n", count);
	stu = (SS*)malloc(count * sizeof(SS));
	while ((!feof(fp)))
	{
		fscanf(fp, "%s%s%f%f\n", (stu[i].number), (stu[i].name), &stu[i].dailyScore, &stu[i].finalScore);
		printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%f��		��ĩ�ɼ�:%f��\n", (stu[i].number), (stu[i].name), stu[i].dailyScore, stu[i].finalScore);

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
	qsort(&(stu[0]), N, sizeof(stu[0]), paiming);//C���Ա������������Դ��Ŀ���������; ��stu��ָ�����������
}
void printOut(SS stu[], int N)
{
	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}
void search(SS stu[], int N, char *id)
{
	int i;

	for (i = 0; i < N; i++)
		if (strcmp(stu[i].number, id) == 0)
		{
			printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%f��		��ĩ�ɼ�:%f��\n", (stu[i].number), (stu[i].name), stu[i].dailyScore, stu[i].finalScore);

			return 0;
		}
	printf("û�ҵ���Ӧ��¼\n");
}
void Analyze(SS stu[], int N)//4.�༶�ɼ�����
{
	float sum_1 = 0, sum_2 = 0,AVG = 0, VAR = 0;
	for (int i = 0; i < N; i++)
	{
		sum_1 += stu[i].generalScore;
	}
	AVG = sum_1 / N;
	printf("�༶�ɼ�ƽ��ֵΪ%f\n", AVG);
	for (int i = 0; i < N; i++)
	{
		sum_2 += (stu[i].generalScore - AVG)*(stu[i].generalScore - AVG);
	}
	VAR = sum_2 / N;
	printf("�༶�ɼ�����Ϊ%f\n", VAR);
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
	printf("����Ҫ��ѯ��ѧ�ţ�");
	scanf("%s", &id);
	search(pstu,N,id);
	Analyze(pstu, N);
	free(pstu);
	system("pause");
}
