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
	printf("----------ͨѶ¼---------\n");
	printf("--------- 1:¼��---------\n");
	printf("----------2:ɾ��---------\n");
	printf("----------3:����---------\n");
	printf("----------4:��ʾ---------\n");
	printf("----------5:����---------\n");
	printf("----------6:����---------\n");
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
	printf("--------------- ɾ�� -----------\n");
	printf("--------------- 1:������ɾ��  -----------\n");
	printf("--------------- 2:�����ϼ��˵�-----------\n");

}
void menu3()
{
	printf("--------------- ���� -----------\n");
	printf("--------------- 1:����������  -----------\n");
	printf("--------------- 2:����������  -----------\n");
	printf("--------------- 3:�����ϼ��˵�-----------\n");

}

//����һ����ͷ�ڵ�ĵ�����
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
		printf("����: %s ����: %s �绰: %s\n", &p->name, &p->city, &p->id);
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
//����������
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
//����������
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
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("�޴���\n");
	}
}
void save(node *head)
{
	node *p = head->next;
	FILE *fp;
	fp = fopen("D://ͨѶ¼2.txt", "a");
	while(fp&&p)
	{
		fprintf(fp, "���� :%-15s ���� :%-15s �绰 :%-15s\n", p->name, p->city, p->id);
		p = p->next;
	}
	fclose(fp);
	printf("����ɹ�\n");
}
void load()
{
	FILE *fp;
	fp = fopen("D://ͨѶ¼2.txt", "r");
	node *p;
	p = (node *)malloc(sizeof(node));
	while(!feof(fp))
	{
		fscanf(fp, "���� :%s ���� :%s �绰 :%s\n", &p->name, &p->city, &p->id);
		printf("���� :%-15s ���� :%-15s �绰 :%-15s\n", p->name, p->city, p->id);
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
			printf("�����빦������");
			while (~scanf("%d", &c)) {
				if (c == 1) {
					printf("��������");
					scanf("%s", name);
					printf("���뼮��");
					scanf("%s", city);
					printf("����绰");
					scanf("%s", &id);
					add(name, city, id, head);
					printf("�����빦������");
				}
				else  if (c == 2) {
					system("cls");
					menu();
					printf("�����빦������");
					break;
				}
			}
			break;
		case 2:
			system("cls");
			menu2();
			int c2;
			printf("�����빦������");
			while (~scanf("%d", &c2)) {
				if (c2 == 1) {
					printf("������ɾ��������");
					scanf("%s", name);
					deletename(name, head);
				}
				else  if (c2 == 2) {
					system("cls");
					menu();
					break;
				}
				else {
					printf("�������\n");
				}
				printf("�����빦������");
			}
			break;
		case 3:
			int n;
			system("cls");
			menu3();
			while (~scanf("%d", &n)) {
				if (n == 1) {
					printf("���������Ľ��Ϊ\n");
					sort1(head);
					println(head);
				}
				else if (n == 2) {
					printf("���������Ľ��Ϊ\n");
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
				printf("������1 �����ϼ��˵�\n");
				int m;
				scanf("%d", &m);
				system("cls");
				menu();
				break;
		case 5:save(head); break;
		case 6:load(); printf("\n"); printf("���سɹ�\n");
		default :
			break;
		}
	
	}
	freelink(head);
	return 0;
}