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
	printf("----------ͨѶ¼---------\n");
	printf("--------- 1:¼��---------\n");
	printf("----------2:��ѯ---------\n");
	printf("----------3:����---------\n");
	printf("----------4:��ʾ---------\n");
	printf("----------5:����---------\n");
	printf("----------6:����---------\n");
	printf("----------7:�޸�---------\n");
	printf("----------8:�˳�---------\n");

}
void menu1()
{
	printf("--------------- ¼��  -----------\n");
	printf("--------- 1:��������    ---------\n");
	printf("--------- 2:�����ϼ��˵�---------\n");
}
void menu2()
{
	printf("--------------- ��ѯ  -----------\n");
	printf("--------------- 1:��������ѯ  -----------\n");
	printf("--------------- 2:��ѧ�Ų�ѯ  -----------\n");
	printf("--------------- 3:�����ϼ��˵�-----------\n");

}
void menu3()
{
	printf("--------------- ���� -----------\n");
	printf("--------------- 1:����������  -----------\n");
	printf("--------------- 2:��ѧ������  -----------\n");
	printf("--------------- 3:�����ϼ��˵�-----------\n");

}
void display(list student[])
{
	int t = size;
	for (int i = 0; i < t; i++)
	{
		printf("������%-10s ,ѧ�ţ�%-5s,�绰��%-5s,���䣺%-5s\n", student[i].name, student[i].id, student[i].telephone, student[i].age);
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
//��������С��������
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
	printf("�밴3�����ϼ��˵�");
	scanf("%d", &t);
	system("cls");
	menu();
}
void add(list student[])
{
	system("cls");
	menu1();
	int n;
	printf("�����빦�ܰ�ť");
	while (~scanf("%d", &n) && n != 2)
	{
		getchar();
		if (n != 1)
		{
			printf("�������");
			scanf("%d", &n);
			if (n == 2)
				break;
		}
		int t = size;
		printf("�������ѧ������\n");
		scanf("%s", student[t].name);
		printf("�������ѧ��ѧ��\n");
		scanf("%s", &student[t].id);
		printf("�������ѧ���绰\n");
		scanf("%s", &student[t].telephone);
		printf("�������ѧ������\n");
		scanf("%s", &student[t].age);
		size += 1;
		printf("�����빦�ܰ�ť");
	}
	system("cls");
	menu();
}
//��ѧ�Ų�ѯ
void query1(list student[])
{
	char s_id[15];
	int flag = 0;
	printf("�������ѯ��ѧ��");
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
		printf("�޴���");
}
void query2(list student[])
{
	char s_name[15];
	int flag = 0;
	printf("�������ѯ������");
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
		printf("�޴���");
}
void query(list student[])
{
	system("cls");
	menu2();
	int t = size;
	printf("�����빦�ܰ�ť");
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
		printf("�����빦�ܰ�ť\n");
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
	p = fopen("D://ͨѶ¼.txt", "at+");
	if (fp == NULL || p == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}
	for (int i = 0; i < t; i++) {
		fwrite(&student[i], sizeof(list), 1, fp);
	}
	for (int i = 0; i < t; i++) {
		fprintf(p, "������%s ,ѧ�ţ�%s,�绰��%s,���䣺%s\n", student[i].name, student[i].id, student[i].telephone, student[i].age);
	}
	rewind(fp);
	fclose(fp);
	fclose(p);
	printf("����ɹ�");
}
void read()
{
	list sstudent[maxsize];
	FILE*fp = fopen("D:\\test.txt", "r");
	if (fp == NULL)
	{
		printf("����Ϣ��\n");
		return;
	}
	//����ָ��
	int i = 0;
	while (fread(&sstudent[i], sizeof(list), 1, fp) == 1) {
		fscanf(fp, "������%s ,ѧ�ţ�%s,�绰��%s,���䣺%s\n", &sstudent[i].name, &sstudent[i].id, &sstudent[i].telephone, &sstudent[i].age);
		printf("������%-10s ,ѧ�ţ�%-5s,�绰��%-5s,���䣺%-5s\n", sstudent[i].name, sstudent[i].id, sstudent[i].telephone, sstudent[i].age);
		i++;
	}
	fclose(fp);
}
void change(list student[])
{
	printf("�������޸�ѧ����Ϣ");
	char na[15];
	scanf("%s", na);
	for (int i = 0; i < size; i++)
	{
		if (strcmp(na, student[i].name) == 0)
		{
			printf("�������ѧ������\n");
			scanf("%s", student[i].name);
			printf("�������ѧ��ѧ��\n");
			scanf("%s", &student[i].id);
			printf("�������ѧ���绰\n");
			scanf("%s", &student[i].telephone);
			printf("�������ѧ������\n");
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