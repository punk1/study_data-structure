#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
int size = 0;
typedef struct student_list
{
	char name[15];
	char id[5];
	char telephone[5];
	char age[5];
}list;

void menu()
{
	printf("----------通讯录---------\n");
	printf("--------- 1:录入---------\n");
	printf("----------2:查询---------\n");
	printf("----------3:排序---------\n");
	printf("----------4:显示---------\n");
	printf("----------5:保存---------\n");
	printf("----------6:加载---------\n");
	printf("----------7:修改---------\n");
	printf("----------8:退出---------\n");

}
void menu1()
{
	printf("--------------- 录入  -----------\n");
	printf("--------- 1:继续增加    ---------\n");
	printf("--------- 2:返回上级菜单---------\n");
}
void menu2()
{
	printf("--------------- 查询  -----------\n");
	printf("--------------- 1:按姓名查询  -----------\n");
	printf("--------------- 2:按学号查询  -----------\n");
	printf("--------------- 3:返回上级菜单-----------\n");

}
void menu3()
{
	printf("--------------- 排序 -----------\n");
	printf("--------------- 1:按姓名排序  -----------\n");
	printf("--------------- 2:按学号排序  -----------\n");
	printf("--------------- 3:返回上级菜单-----------\n");

}
void display(list student[])
{
	int t = size;
	for (int i = 0; i < t; i++)
	{
		printf("姓名：%-10s ,学号：%-5s,电话：%-5s,年龄：%-5s\n", student[i].name, student[i].id, student[i].telephone, student[i].age);
	}

}
void swap(list *a, list *b)
{

	list c;
	strcpy(c.name, a->name);
	strcpy(a->name, b->name);
	strcpy(b->name, c.name);
	strcpy(c.id, a->id);
	strcpy(a->id, b->id);
	strcpy(b->id, c.id);
	strcpy(c.telephone, a->telephone);
	strcpy(a->telephone, b->telephone);
	strcpy(b->telephone, c.telephone);
	strcpy(c.age, a->age);
	strcpy(a->age, b->age);
	strcpy(b->age, a->age);
}
//按姓名从小到大排序
void sort1(list student[])
{
	int t = size;
	for (int i = 0; i <t - 1; i++)
	{
		for (int j = i + 1; j < t; j++)
		{
			if (strcmp(student[i].name, student[j].name) > 0)
			{
				swap(&student[i], &student[j]);
			}
		}
	}
	display(student);
}
void sort2(list student[])
{
	int t = size;
	for (int i = 0; i <t - 1; i++)
	{
		for (int j = i; j < t; j++)
		{
			if (student[i].id>student[j].id)
			{
				swap(&student[i], &student[j]);
			}
		}
	}
	display(student);
}
void sort(list student[])
{
	system("cls");
	menu3();
	int n;
	scanf("%d", &n);
	switch (n)
	{
	case 1:sort1(student); break;
	case 2:sort2(student); break;
	default:
		break;
	}
	int t;
	printf("请按3返回上级菜单");
	scanf("%d", &t);
	system("cls");
	menu();
}
void add(list student[])
{
	system("cls");
	menu1();
	int n;
	printf("请输入功能按钮");
	while (~scanf("%d", &n) && n != 2)
	{
		getchar();
		if (n != 1)
		{
			printf("输入错误！");
			scanf("%d", &n);
			if (n == 2)
				break;
		}
		int t = size;
		printf("请输入该学生姓名\n");
		scanf("%s", student[t].name);
		printf("请输入该学生学号\n");
		scanf("%s", &student[t].id);
		printf("请输入该学生电话\n");
		scanf("%s", &student[t].telephone);
		printf("请输入该学生年龄\n");
		scanf("%s", &student[t].age);
		size += 1;
		printf("请输入功能按钮");
	}
	system("cls");
	menu();
}
//按学号查询
void query1(list student[])
{
	char s_id[15];
	int flag = 0;
	printf("请输入查询的学号");
	scanf("%s", s_id);
	int t = size;
	for (int i = 0; i < t; i++)
	{
		if (strcpy(student[i].id, s_id)) {
			printf("%s\n", student[i].name);
			printf("%s\n", student[i].id);
			printf("%s\n", student[i].telephone);
			printf("%s\n", student[i].age);
			flag = 1;
			break;
		}
		else
			i++;
	}
	if (!flag)
		printf("无此人");
}
void query2(list student[])
{
	char s_name[15];
	int flag = 0;
	printf("请输入查询的姓名");
	scanf("%s", s_name);
	int t = size;
	for (int i = 0; i < t; i++)
	{
		if (strcmp(s_name, student[i].name) == 0)
		{
			printf("%s\n", student[i].name);
			printf("%s\n", student[i].id);
			printf("%s\n", student[i].telephone);
			printf("%s\n", student[i].age);
			flag = 1;
			break;
		}
		else
			i++;
	}
	if (!flag)
		printf("无此人");
}
void query(list student[])
{
	system("cls");
	menu2();
	int t = size;
	printf("请输入功能按钮");
	int n;
	while (~scanf("%d", &n) && n != 3)
	{
		switch (n)
		{
		case 1:query2(student); display(student); break;
		case 2:query1(student); display(student); break;
		default:
			break;
		}
		printf("请输入功能按钮\n");
	}
	system("cls");
	menu();
}
void save(list student[])
{
	int t = size;
	FILE *fp = NULL;
	FILE *p = NULL;
	fp = fopen("D://test.txt", "at+");
	p = fopen("D://通讯录.txt", "at+");
	if (fp == NULL || p == NULL)
	{
		printf("文件打开失败");
		return;
	}
	for (int i = 0; i < t; i++) {
		fwrite(&student[i], sizeof(list), 1, fp);
	}
	for (int i = 0; i < t; i++) {
		fprintf(p, "姓名：%s ,学号：%s,电话：%s,年龄：%s\n", student[i].name, student[i].id, student[i].telephone, student[i].age);
	}
	rewind(fp);
	fclose(fp);
	fclose(p);
	printf("保存成功");
}
void read()
{
	list sstudent[maxsize];
	FILE*fp = fopen("D:\\test.txt", "r");
	if (fp == NULL)
	{
		printf("无信息！\n");
		return;
	}
	//操作指针
	int i = 0;
	while (fread(&sstudent[i], sizeof(list), 1, fp) == 1) {
		fscanf(fp, "姓名：%s ,学号：%s,电话：%s,年龄：%s\n", &sstudent[i].name, &sstudent[i].id, &sstudent[i].telephone, &sstudent[i].age);
		printf("姓名：%-10s ,学号：%-5s,电话：%-5s,年龄：%-5s\n", sstudent[i].name, sstudent[i].id, sstudent[i].telephone, sstudent[i].age);
		i++;
	}
	fclose(fp);
}
void change(list student[])
{
	printf("请输入修改学生信息");
	char na[15];
	scanf("%s", na);
	for (int i = 0; i < size; i++)
	{
		if (strcmp(na, student[i].name) == 0)
		{
			printf("请输入该学生姓名\n");
			scanf("%s", student[i].name);
			printf("请输入该学生学号\n");
			scanf("%s", &student[i].id);
			printf("请输入该学生电话\n");
			scanf("%s", &student[i].telephone);
			printf("请输入该学生年龄\n");
			scanf("%s", &student[i].age);
		}
	}
}
int main()
{

	menu();
	int n;
	list student[maxsize];
	size = 0;
	while (~scanf("%d", &n))
	{
		switch (n)
		{
		case 1:add(student); break;
		case 2:query(student); break;
		case 3:sort(student);  break;
		case 4:display(student); break;
		case 5:save(student); break;
		case 6:read(); break;
		case 7:change(student); break;
		default:
			break;
		}
		if (n > 7 || n < 1)
			break;
	}
	system("pause");
	return 0;
}