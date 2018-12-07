#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#define M 100 
typedef struct student
{
	int   id;
	char name[10];
	int  classname;
	char  xi[10];
} s;
s stu[M];
int count;
void menu()
{
	printf("----------����Ͳ���ϵͳ----------\n");
	printf("----------1:����ѧ����Ϣ----------\n");
	printf("----------    2:����    ----------\n");
	printf("----------    3:����    ----------\n");
}
void sort1(s a[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r;
		s x = a[l];
		while (i < j)
		{
			while (i < j&&a[j].id >= x.id)
			{
				j--;
			}
			if (i < j) { a[i++] = a[j]; }
			while (i < j&&a[i].id <= x.id) i++;
			if (i < j) { a[j--] = a[i]; }
		}
		a[i] = x;
		sort1(a, l, i - 1);
		sort1(a, i + 1, r);
	}
}
void sort2(s a[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r;
		s x = a[l];
		while (i < j)
		{
			while (i < j&&strcmp(a[i].name,x.name)>=0)
			{
				j--;
			}
			if (i < j) { a[i++] = a[j]; }
			while (i < j&&strcmp(a[i].name,x.name)<=0) i++;
			if (i < j) { a[j--] = a[i]; }
		}
		a[i] = x;
		sort2(a, l, i - 1);
		sort2(a, i + 1, r);
	}
}
void read()
{
	system("cls");
	FILE *fp;
	fp = fopen("D://teststudent.txt", "r");
	if (fp) {
		fscanf(fp,"%d\n", &count);
		for (int i = 0; i < count; i++)
		{
			fscanf(fp, "%d %s %d %s\n", &stu[i].id, &stu[i].name, &stu[i].classname, &stu[i].xi);
			printf("ѧ��:%-10d ����:%-10s �༶��%-5d ϵ��:%-10s\n",stu[i].id,stu[i].name,stu[i].classname,stu[i].xi);
		}
	}
	fclose(fp);
	printf("�밴1�����ϼ��˵�");
	int n;
	scanf("%d", &n);
	while (n != 1)
	{
		printf("����������");
	}
	if (n == 1)
	{
		system("cls");
		menu();
	}
}
void menu2()
{
	printf("----------    ����      ----------\n");
	printf("----------    1:ѧ��    ----------\n");
	printf("----------    2:����    ----------\n");

}
void println(s stu[])
{
	for (int i = 0; i < count; i++)
	{
				printf("ѧ��:%-10d ����:%-10s �༶��%-5d ϵ��:%-10s\n", stu[i].id, stu[i].name, stu[i].classname, stu[i].xi);
	}
	printf("�밴1�����ϼ��˵�");
	int n;
	scanf("%d", &n);
	while (n != 1)
	{
		printf("����������");
	}
	if (n == 1)
	{
		system("cls");
		menu();
	}
}
int binsearch(s stu[], int k)
{
	int low = 0, high = count - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (stu[mid].id == k)
			return mid;
		if (stu[mid].id > k)
			high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
int main()
{
	int n;
	FILE *fp;
	fp = fopen("D://teststudent.txt", "r");
	if (fp)
	{
		fscanf(fp,"%d", &count);
	}
	fclose(fp);
	menu();
	while (~scanf("%d", &n)&&n<=3)
	{
		switch (n)
		{
		case 1: read(); break;
		case 2:system("cls"); menu2();
			int c;
			scanf("%d", &c);
			if (c == 1) {
				sort1(stu, 0, count - 1); println(stu); break;
			}
			else if (c == 2) {
				sort2(stu, 0, count - 1); println(stu); break;
			}
		case 3:
			system("cls");
			sort1(stu, 0, count - 1);
			printf("�������ѯ��ѧ��");
			int num;
			scanf("%d", &num);
			int ans = 0;
			ans=binsearch(stu, num);
			if (ans>=0)
			{
				int i = ans;
				printf("ѧ��:%-10d ����:%-10s �༶��%-5d ϵ��:%-10s\n", stu[i].id, stu[i].name, stu[i].classname, stu[i].xi);
			}
			else
				printf("�޴���");
			printf("�밴1�����ϼ��˵�");
			int n;
			scanf("%d", &n);
			while (n != 1)
			{
				printf("����������");
			}
			if (n == 1)
			{
				system("cls");
				menu();
			}
			break;
		}
	}
	return 0;
}