#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
int size = 0;
typedef struct student_list
{
	char name[15];
	char city[15];
	char id[15];
	struct student_list *next;
}node;
node *p_end = NULL;
void menu()
{
	printf("----------通讯录---------\n");
	printf("--------- 1:录入---------\n");
	printf("----------2:删除---------\n");
	printf("----------3:排序---------\n");
	printf("----------4:显示---------\n");
	printf("----------5:保存---------\n");
	printf("----------6:加载---------\n");
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
	printf("--------------- 删除 -----------\n");
	printf("--------------- 1:按姓名删除  -----------\n");
	printf("--------------- 2:返回上级菜单-----------\n");

}
void menu3()
{
	printf("--------------- 排序 -----------\n");
	printf("--------------- 1:按姓名排序  -----------\n");
	printf("--------------- 2:按籍贯排序  -----------\n");
	printf("--------------- 3:返回上级菜单-----------\n");

}

//建立一个带头节点的单链表
node *init()
{
	node *head;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	return head;
}
void add(char name[], char city[], char id[], node *head)
{
	node *p_new;
	p_new = (node *)malloc(sizeof(node));
	strcpy(p_new->name, name);
	strcpy(p_new->city, city);
	strcpy(p_new->id,id);
	p_new->next = NULL;
	if (p_end == NULL) {
		head->next = p_new;
		p_end = p_new;
	}
	else
	{
		p_end->next = p_new;
		p_end = p_new;
	}
}
void println(node * head)
{
	node *p;
	p = head->next;
	while (p) 
	{
		printf("姓名: %s 籍贯: %s 电话: %s\n", &p->name, &p->city, &p->id);
		p = p->next;
	}
}
void swap(node *a, node *b) {
	node *c;
	c = (node*)malloc(sizeof(node));
	strcpy(c->name, a->name);
	strcpy(c->city, a->city);
	strcpy(c->id, a->id);
	strcpy(a->name, b->name);
	strcpy(a->city, b->city);
	strcpy(a->id, b->id);
	strcpy(b->name, c->name);
	strcpy(b->city, c->city);
	strcpy(b->id, c->id);
}
//按姓名排序
void sort1(node *head)
{
	node *p;
	p = head->next;
	node *pre = head;
	while (p->next&&pre->next) {
		p = p->next;
		pre = pre->next;
		if (strcmp(pre->name, p->name) > 0) {
			swap(pre, p);
		}
	}
}
//按籍贯排序
void sort2(node *head)
{
	node *p;
	p = head->next;
	node *pre = head;
	while (p->next&&pre->next) {
		p = p->next;
		pre = pre->next;
		if (strcmp(pre->city, p->city) > 0) {
			swap(pre, p);
		}
	}
}
void freelink(node *head)
{
	node*p_new = head->next;
	while (head != NULL)
	{
		p_new = head;
		head = head->next;
		free(p_new);
	}
}
node *find(char name[], node *head)
{
	node *p;
	p = head->next;
	node *pre;
	pre = head;
	while (p)
	{
		if (strcmp(p->name, name) != 0)
		{
			pre = p;
			p = p->next;
		}
	}
	if (p)
		return p;
	else
		return NULL;
}
void deletename(char name[],node *head)
{
	node *p;
	p = head->next;
	node *pre;
	pre = head;
	while (p)
	{
		if (strcmp(p->name, name) != 0)
		{
			pre = p;
			p = p->next;
		}
		else
			break;
	}
	if (p)																													
	{
		pre->next = p->next;
		free(p);
		printf("删除成功\n");
	}
	else
	{
		printf("无此人\n");
	}
}
void save(node *head)
{
	node *p = head->next;
	FILE *fp;
	fp = fopen("D://通讯录2.txt", "a");
	while(fp&&p)
	{
		fprintf(fp, "姓名 :%-15s 籍贯 :%-15s 电话 :%-15s\n", p->name, p->city, p->id);
		p = p->next;
	}
	fclose(fp);
	printf("保存成功\n");
}
void load()
{
	FILE *fp;
	fp = fopen("D://通讯录2.txt", "r");
	node *p;
	p = (node *)malloc(sizeof(node));
	while(!feof(fp))
	{
		fscanf(fp, "姓名 :%s 籍贯 :%s 电话 :%s\n", &p->name, &p->city, &p->id);
		printf("姓名 :%-15s 籍贯 :%-15s 电话 :%-15s\n", p->name, p->city, p->id);
	}
	fclose(fp);
}
int main()
{
	int n;
	menu();
	node *head = init();
	char name[15] = { '\0' };
	char city[15] = { '\0' };
	char id[15] = { '\0' };
	
	while (~scanf("%d", &n))
	{
		switch (n)
		{
		case 1:
			system("cls");
			menu1();
			int c;
			printf("请输入功能描述");
			while (~scanf("%d", &c)) {
				if (c == 1) {
					printf("输入姓名");
					scanf("%s", name);
					printf("输入籍贯");
					scanf("%s", city);
					printf("输入电话");
					scanf("%s", &id);
					add(name, city, id, head);
					printf("请输入功能描述");
				}
				else  if (c == 2) {
					system("cls");
					menu();
					printf("请输入功能描述");
					break;
				}
			}
			break;
		case 2:
			system("cls");
			menu2();
			int c2;
			printf("请输入功能描述");
			while (~scanf("%d", &c2)) {
				if (c2 == 1) {
					printf("请输入删除的姓名");
					scanf("%s", name);
					deletename(name, head);
				}
				else  if (c2 == 2) {
					system("cls");
					menu();
					break;
				}
				else {
					printf("输入错误\n");
				}
				printf("请输入功能描述");
			}
			break;
		case 3:
			int n;
			system("cls");
			menu3();
			while (~scanf("%d", &n)) {
				if (n == 1) {
					printf("姓名排序后的结果为\n");
					sort1(head);
					println(head);
				}
				else if (n == 2) {
					printf("籍贯排序后的结果为\n");
					sort2(head);
					println(head);
				}
				else {
					system("cls");
					menu();
					break;
				}
			}
		
			break;
		case 4: system("cls"); 
			    println(head); 
				printf("请输入1 返回上级菜单\n");
				int m;
				scanf("%d", &m);
				system("cls");
				menu();
				break;
		case 5:save(head); break;
		case 6:load(); printf("\n"); printf("加载成功\n");
		default :
			break;
		}
	
	}
	freelink(head);
	return 0;
}