# include <cstdio>
# include <cstdlib>
#include <iostream>
using namespace std;
#define maxsize 100
 struct node{
	 char name[14];
	 char price[12];
};
 typedef struct lnode {
	 node data;
	 struct lnode *lchild, *rchild;
 }bnode;

 //ջ�ṹ����
 typedef struct stack {
	 bnode * data[100];
	 int tag[100];
	 int top;
 }seqstack;
 void push(seqstack *s,bnode *t) {//��ջ
	 s->data[s->top] = t;
	 s->top++;
}
 bnode *pop(seqstack *s)
 {
	 if (s->top != 0) {
		 s->top--;
		 return s->data[s->top];
	 }
	 else
		 return NULL;
 }
 bnode *head;
 int flag=0;
void menu()
{
	printf("---------������ʵ��------------\n");
	printf("--------- 1:����      ---------\n");
	printf("----------2:�ݹ����  ---------\n");
	printf("----------3:�ǵݹ����---------\n");
	printf("----------4:����      ---------\n");
	printf("----------5:�˳�      ---------\n");
}
void menu2()
{
	printf("---------1:ǰ�����------------\n");
	printf("---------2:�������------------\n");
	printf("---------3:�������------------\n");
	printf("---------4:�����ϼ�------------\n");
}
void menu1()
{
	printf("---------    ����      ---------\n");
}
bnode *create()
{
	bnode *t;
	node s;
	FILE *fp;
	
	printf("Ʒ����\n");
	cin >> s.name;
	if (s.name[0] != '#')
	{
		printf("�۸�\n");
		cin >> s.price;
		
	}
	if (s.name[0] == '#' || s.price[0] == '#')
	{
		t = NULL;
	}
	else
	{
		if (!flag) {
			flag = 1;
			t = head;
			t->data = s;
			t->lchild = create();
			t->rchild = create();
		
		}
		t = (bnode *)malloc(sizeof(bnode));
		t->data = s;
		fp = fopen("D://test2.txt", "a");
		if (fp) {
			fprintf(fp, "Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
		}
		fclose(fp);
		t->lchild = create();
		t->rchild = create();

	}
	return t;
}
void preorder(bnode *t)
{
	
	if (t)
	{
		printf("Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void inorder(bnode *t)
{
	if (t)
	{
		inorder(t->lchild);
		printf("Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
		inorder(t->rchild);
	}
}
void postorder(bnode *t)
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
		
	}
}
void println()
{
	system("cls");
	menu2();
	int n;
	printf("��������Ĺ�������");
	while (~scanf("%d", &n)) {
		switch (n)
		{
		case 1: preorder(head); break;
		case 2:inorder(head); break;
		case 3:postorder(head); break;
		default:
			break;
		}
		if (n == 4) {
			system("cls");
			menu();
			break;
		}
	}
}
void fpreorder(bnode *t)
{
	seqstack s;
	s.top = 0;
	while ((t) || (s.top != 0)) 
	{
		if (t)
		{
			printf("Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
			push(&s, t);
			t = t->lchild;
		}
		else
		{
			t = pop(&s);
			t = t->rchild;
		}
	}
}
void finorder(bnode *t)
{
	seqstack s;
	s.top = 0;
	while ((t) || (s.top != 0))
	{
		if (t)
		{
			push(&s, t);
			t = t->lchild;
		}
		else
		{
			t = pop(&s);
			printf("Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
			t = t->rchild;
		}
	}
}
void fpostorder(bnode *t)
{
	seqstack s;
	s.top = 0;
	while ((t) || s.top != 0)
	{
		if (t)
		{
			s.tag[s.top] = 0;
			push(&s, t);
			t = t->lchild;
		}
		else {
			if (s.tag[s.top - 1] == 1)
			{
				s.top--;
				t = s.data[s.top];
				printf("Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
				t = NULL;
			}
			else
			{
				t = s.data[s.top - 1];
				s.tag[s.top - 1] = 1;
				t = t->rchild;
			}
		}
	}
}
void fprintln()
{
	system("cls");
	menu2();
	int n;
	printf("��������Ĺ�������");
	while (~scanf("%d", &n)) {
		switch (n)
		{
		case 1: fpreorder(head); break;
		case 2:finorder(head); break;
		case 3:fpostorder(head); break;
		default:
			break;
		}
		if (n == 4) {
			system("cls");
			menu();
			break;
		}
	}
}
void load()
{
	FILE *fp;
	fp = fopen("D://test2.txt", "r");
	bnode *t;
	t = (bnode *)malloc(sizeof(bnode));
	while (!feof(fp))
	{
		fscanf(fp, "Ʒ���� ��%s �۸� :%s\n", &t->data.name, &t->data.price);
		printf("Ʒ���� ��%-15s �۸� :%-10s\n", t->data.name, t->data.price);
	}

}
int main()
{
	menu();
	int n;
	head = (bnode *)malloc(sizeof(bnode));
	head->lchild = head->rchild = NULL;
	while (~scanf("%d", &n)) {
		switch (n)
		{
		case 1:system("cls"); menu1(); create();  printf("�������"); system("cls");menu(); break;
		case 2:system("cls"); menu2(); println(); break;
		case 3:fprintln(); break;
		case 4:load(); break;
		default:
			break;
		}
		if (n < 1 || n>3)
			break;
	}
	system("pause");
}