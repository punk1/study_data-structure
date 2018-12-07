# include <cstdio>
#include <queue>
#include <stack>
using namespace std;
#define FFINITY 5000   //���������
# define M 20
typedef char vertextype;//����ֵ����
typedef int edgetyoe;//Ȩֵ����
typedef struct {
	vertextype vexs[M];//������Ϣ��
	edgetyoe edges[M][M];//�ڽӾ���
	int n, e;//ͼ�ж������������
}Mgraph;
bool visit[M];//���ʱ�ǵ�����
typedef  int dis[M];
typedef  int path[M];
//���ļ��ж�ȡ��Ϣ
void create(Mgraph *g)
{
	int i, j, k, w;
	FILE *rf;
	rf = fopen("D://graph.txt", "r");//���ļ��ж�ȡͼ����Ϣ
	if (rf)
	{
		fscanf(rf, "%d %d\n", &g->n, &g->e);//����ͼ�Ķ���ֵ�����
		printf("%d %d\n", g->n,g->e);
		for (int i = 0; i < g->n; i++)
		{
			fscanf(rf, "%c", &g->vexs[i]);
			printf("%c ", g->vexs[i]);
		} //����ͼ�Ķ���ֵ
		printf("\n");									//��ʼ���ڽӾ���
		for (int i = 0; i < g->n; i++)
		{
			for (int j = 0; j < g->n; j++)
			{
				if (i == j)
					g->edges[i][j] = 0;
				else
					g->edges[i][j] = FFINITY;
			}
		}
		//���������еı�
		for ( k = 0; k < g->e; k++)
		{
			fscanf(rf, "%d%d%d\n", &i, &j, &w);
			printf("%d %d %d\n", i, j, w);
			g->edges[i][j] = w;
		}
		fclose(rf);
	}
	else
		g->n = 0;
}
void dijkstra(Mgraph g, int v0,int vv, path p, dis d)
{
	bool final[M];
	int i, k, v, min;
	for (v = 0; v < g.n; v++)
	{
		final[v] = false;
		d[v] = g.edges[v0][v];
		if (d[v] < FFINITY &&d[v] != 0)
		{
			p[v] = v0;
		}
		else
			p[v] = -1;
	}
	final[v0] = true;
	d[v0] = 0;
	for ( i = 1; i < g.n; i++)
	{
		min = FFINITY;
		for (k = 0; k < g.n; k++)
		{
			if (!final[k] && d[k] < min) {
				v = k;
				min = d[k];
			}
		}
		if (min == FFINITY) return;
		final[v] = true;
		for (k = 0; k < g.n; k++)
		{
			if (!final[k] && (min + g.edges[v][k] < d[k]))
			{
				d[k] = min + g.edges[v][k];
				p[k] = v;
			}
		}
	}
	printf("\n");
	printf("%c->%c�����·������Ϊ%d   ��·��Ϊ:", g.vexs[v0], g.vexs[vv],d[vv]);
	stack<int > s;
	s.push(vv);
	while (p[vv]!=v0)
	{
		s.push(p[vv]);
		vv = p[vv];
	}
	printf("%c ", g.vexs[v0]);
	while (!s.empty())
	{
		int t = s.top();
		s.pop();
		printf("%c ", g.vexs[t]);
	}
	printf("\n");
}

void floyed(Mgraph g, int p[M][M] , int  d[M][M],int v0,int vv)
{
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			d[i][j] = g.edges[i][j];
			if (i != j && d[i][j]<FFINITY )
			{
				p[i][j] = i;
			}
			else p[i][j] = -1;
		}
	}
	for (int k = 0; k < g.n; k++)
	{
		for (int i = 0; i < g.n; i++)
		{
			for (int j = 0; j < g.n; j++)
			{
				if (d[i][j] > (d[i][k] + d[k][j]))
				{
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
		}
	}
	printf("%c->%c�����·������Ϊ %d :·��Ϊ��",g.vexs[v0], g.vexs[vv],d[v0][vv]);
	printf("%c ", g.vexs[v0]);
	while (p[v0][vv] != v0)
	{
		printf("%c ", g.vexs[p[v0][vv]]);
		v0 = p[v0][vv];
	}
	printf("%c ", g.vexs[vv]);
}
void menu()
{
	printf("---------��ͨ·����ѯϵͳ---------\n");
	printf("----------1:�������·��----------\n");
	printf("----------2:������·��----------\n");
	printf("----------3:�����ϼ��˵�----------\n");
}
int main()
{
	Mgraph g;
	menu();
	create(&g);
	int c;
	while (~scanf("%d", &c)) {
		if (c == 1) {
			system("cls");
			printf("������Դ��");
			int n;
			path p;
			dis d;
			scanf("%d", &n);
			printf("�������ѯ��");
			int cc;
			scanf("%d", &cc);
			dijkstra(g, n, cc, p, d);
			printf("�밴3�����ϼ��˵�");
		}
		else if (c == 2)
		{
			system("cls");
			printf("���������");
			int n;
			int pp[M][M];
			int dd[M][M];
			scanf("%d", &n);
			printf("�������ѯ��");
			int cc;
			scanf("%d", &cc);
			floyed(g, pp, dd, n, cc);
			printf("�밴3�����ϼ��˵�");
		}
		else if (c == 3) {
			system("cls");
			menu();
		}
	}
	system("pause");
}