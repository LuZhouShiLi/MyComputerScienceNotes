#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

FILE* open_file(char *str)
{
	FILE* fp = fopen("calc.txt", str);
	

	return fp;


}

// 获取随机数  然后写入文件
void get_date()
{
	FILE* fp1 = open_file("w");
	char abb[4] = {'+','-','*','/'};
	srand(time(NULL));// 产生随机数种子
	int a = 0;
	int b = 0;
	char c = 0;
	char cmd[1024] = "";
	for (int i = 0; i < 10; i++)
	{
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		c = rand() % 4;// 产生随机值 0 1 2 3
		sprintf(cmd,"%d%c%d=\n",a,abb[c],b);// 按照格式写入cmd字符串中  记得加上换行符
		fputs(cmd,fp1);
		printf("%s",cmd);
	}
	fclose(fp1);
}

void read_data()
{
	FILE* fp2 = open_file("r");
	int a = 0;
	int b = 0;
	char c = 0;// 运算符
	char buf[128] = "";
	int num = 0;
	char cmd[10][128] = {0};
	int len = 0;
	char* p = NULL;
	int i = 0;

	while (1)
	{
		p = fgets(buf,sizeof(buf),fp2);

		if (p == NULL)
		{
			break;
		}

		sscanf(buf,"%d%c%d",&a,&c,&b);// 从buf中读出a c b

		switch (c)
		{
			case '+':
				num = a + b;
				break;

			case '-':
				num = a - b;
				break;

			case '*':
				num = a * b;
				break;

			case '/':
				num = a / b;
				break;
		}

		

		// 开始组包
		sprintf(cmd[i],"%d%c%d=%d\n",a,c,b,num);
		i++;
	}

	fclose(fp2);

	FILE* fp3 = open_file("w");

	int j = 0;
	for (j = 0; j < i; j++)
	{
		fputs(cmd[j],fp3);
	}

	fclose(fp3);
}

int main()
{
	get_date();
	read_data();
	return 0;
}
