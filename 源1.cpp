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

 //栈结构定义
 typedef struct stack {
	 bnode * data[100];
	 int tag[100];
	 int top;
 }seqstack;
 void push(seqstack *s,bnode *t) {//进栈
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
	printf("---------二叉树实验------------\n");
	printf("--------- 1:建立      ---------\n");
	printf("----------2:递归遍历  ---------\n");
	printf("----------3:非递归遍历---------\n");
	printf("----------4:加载      ---------\n");
	printf("----------5:退出      ---------\n");
}
void menu2()
{
	printf("---------1:前序遍历------------\n");
	printf("---------2:中序遍历------------\n");
	printf("---------3:后序遍历------------\n");
	printf("---------4:返回上级------------\n");
}
void menu1()
{
	printf("---------    建立      ---------\n");
}
bnode *create()
{
	bnode *t;
	node s;
	FILE *fp;
	
	printf("品牌名\n");
	cin >> s.name;
	if (s.name[0] != '#')
	{
		printf("价格\n");
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
			fprintf(fp, "品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
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
		printf("品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void inorder(bnode *t)
{
	if (t)
	{
		inorder(t->lchild);
		printf("品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
		inorder(t->rchild);
	}
}
void postorder(bnode *t)
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
		
	}
}
void println()
{
	system("cls");
	menu2();
	int n;
	printf("请输入你的功能描述");
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
			printf("品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
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
			printf("品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
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
				printf("品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
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
	printf("请输入你的功能描述");
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
		fscanf(fp, "品牌名 ：%s 价格 :%s\n", &t->data.name, &t->data.price);
		printf("品牌名 ：%-15s 价格 :%-10s\n", t->data.name, t->data.price);
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
		case 1:system("cls"); menu1(); create();  printf("创建完成"); system("cls");menu(); break;
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