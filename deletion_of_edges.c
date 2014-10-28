#include<stdio.h>
#include<stdlib.h>
typedef struct node	//Node is used to store the edge.
{
	int v1;
	int v2;
	int weight;
}node;
typedef struct list	//List stores the adjacency list of a vertex.
{
	int data;
	struct list *next;
}list;
int visited[10001];	//to check if the node has been visited or not.
list *l[10001];		//array of lists to store the adjacency list for each node.
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
void rec(node n,list *li)	//to check for connectivity - dfs
{
	list *temp=l[li->data];
	visited[n.v1]=1;
	while(temp->next!=NULL)
	{
		if((temp->next)->data==n.v2 && li->data==n.v1)			//ignoring the edge we are currently evaluating
		{
			temp=temp->next;
			continue;
		}
		else if(visited[(temp->next)->data]==1)					//ignoring the edge, which is already visited
		{
			temp=temp->next;
			continue;
		}
		visited[(temp->next)->data]=1;							//making the unvisited edge visited
		rec(n,temp->next);									
		temp=temp->next;
	}
	return;
}
int main()
{
	int edges,vertices;
	node n[10001];
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&vertices);
		scanf("%d",&edges);
		int i;
		for(i=1;i<=vertices;i++)
		{
			l[i]=(list *)malloc(sizeof(list));
			l[i]->data=i;
			l[i]->next=NULL;
		}
		for(i=1;i<=edges;i++)
		{
			scanf("%d",&n[i].v1);
			scanf("%d",&n[i].v2);
			scanf("%d",&n[i].weight);
			list *temp=l[n[i].v1]->next;
			list *t=(list *)malloc(sizeof(list));	//adding v2 to the adjacency list of v1
			t->data=n[i].v2;
			if(temp==NULL)
				t->next=NULL;
			else
				t->next=temp;
			l[n[i].v1]->next=t;
			temp=l[n[i].v2]->next;
			t=(list *)malloc(sizeof(list));			//adding v1 to the adjacency list of v2
			t->data=n[i].v1;
			if(temp==NULL)
				t->next=NULL;
			else
				t->next=temp;
			l[n[i].v2]->next=t;
		}
		int flag,j;
		printf("The edges in the minimum spanning tree are:\n");
		qsort((void *)&n,edges+1,sizeof(node),(compfn)compare);
		for(i=edges;i>0;i--)
		{
			flag=0;
			rec(n[i],l[n[i].v1]);					//rec() is the depth-first-search function
			for(j=1;j<=vertices;j++)
				if(visited[j]==0)
				{
					flag=1;
					break;
				}
			if(flag==1)
				printf("%d %d %d\n",n[i].v1,n[i].v2,n[i].weight);			//printing the edge if it is a part of the MST
			else
			{
				list *temp=l[n[i].v1];
				while(temp!=NULL)
				{
					if((temp->next)->data==n[i].v2)							//deleting v2 from the adjacency list of v1
					{
						list *t=temp->next;
						if((temp->next)->next==NULL)
							temp->next=NULL;
						else
							temp->next=(temp->next)->next;
						free(t);
						break;
					}
					temp=temp->next;
				}
				temp=l[n[i].v2];
				while(temp!=NULL)
				{
					if((temp->next)->data==n[i].v1)							//deleting v1 from the adjacency list of v2
					{
						list *t=temp->next;
						if((temp->next)->next==NULL)
							temp->next=NULL;
						else
							temp->next=(temp->next)->next;
						free(t);
						break;
					}
					temp=temp->next;
				}
			}
			for(j=1;j<=vertices;j++)
				visited[j]=0;
		}
	}
	return 0;
}
