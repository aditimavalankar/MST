#include<stdio.h>
int parent[10000],size[10000];
int findset(int a)					//to find the parent of vertex a
{
	if(parent[a]==-1)
		return a;
	return findset(parent[a]);
}
void findunion(int a,int b)			//to find the union of 2 vertices i.e. to make them belong to the set
{
	int x=findset(a),y=findset(b);
	if(x==y)
		return;
	if(size[x]>=size[y])
	{
		parent[y]=x;
		size[x]+=size[y];
	}
	else if(size[x]<size[y])
	{
		parent[x]=y;
		size[y]+=size[x];
	}
	return;
}
typedef struct node
{
	int x;
	int y;
	int weight;
}node;
typedef int (*compfn)(const void*,const void*);
int compare(node *n1,node *n2)
{
	if(n1->weight>n2->weight)
		return 1;
	else if(n1->weight==n2->weight)
		return 0;
	else 
		return -1;
}
int main()
{
	int n,m;
	node nd[10000];
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		int i;
		for(i=0;i<n;i++)
		{
			parent[i]=-1;
			size[i]=1;
		}
		int a,b;
		for(i=0;i<m;i++)
			scanf("%d%d%d",&nd[i].x,&nd[i].y,&nd[i].weight);
		qsort((void *)&nd,m+1,sizeof(node),(compfn)compare);			//sorting in increasing order of weights of edges
		printf("The edges in the minimum spanning tree are:\n");
		for(i=0;i<m;i++)
			if(findset(nd[i].x)!=findset(nd[i].y))
			{
				printf("%d %d %d\n",nd[i].x,nd[i].y,nd[i].weight);
				findunion(nd[i].x,nd[i].y);
			}
	}
	return 0;
}
